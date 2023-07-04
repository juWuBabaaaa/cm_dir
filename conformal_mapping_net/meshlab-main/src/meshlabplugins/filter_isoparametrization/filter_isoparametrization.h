/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2007                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef FILTERISOPARAMPLUGIN_H
#define FILTERISOPARAMPLUGIN_H

#include <parametrizator.h>
#include <iso_parametrization.h>
#include <diamond_sampler.h>
#include <diam_parametrization.h>
#include <stat_remeshing.h>
#include <common/plugins/interfaces/filter_plugin.h>

class FilterIsoParametrization : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum {ISOP_PARAM,
			ISOP_REMESHING,
			ISOP_DIAMPARAM,
			ISOP_TRANSFER
		 };

	FilterIsoParametrization();
	~FilterIsoParametrization();

	QString pluginName() const;
	virtual FilterClass getClass(const QAction*) const;
	virtual QString filterName(ActionIDType filter) const;
	QString pythonFilterName(ActionIDType f) const;
	virtual QString filterInfo(ActionIDType filter) const;

	virtual int getRequirements(const QAction*);

	RichParameterList initParameterList(const QAction*, const MeshDocument&);
	std::map<std::string, QVariant> applyFilter(
			const QAction* action,
			const RichParameterList & parameters,
			MeshDocument &md,
			unsigned int& postConditionMask,
			vcg::CallBackPos * cb);
	int postCondition(const QAction* filter) const;
	void PrintStats(CMeshO *mesh);
	FilterArity filterArity(const QAction*) const;
};
#endif
