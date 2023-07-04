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

#ifndef FILTERFRACTALPLUGIN_H
#define FILTERFRACTALPLUGIN_H

#include <QObject>
#include <QStringList>
#include <QString>

#include <common/plugins/interfaces/filter_plugin.h>
#include "craters_utils.h"

class FilterFractal : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

	public:
		FilterFractal();
	~FilterFractal(){}

	QString pluginName() const;
	QString pythonFilterName(ActionIDType f) const;
	QString filterName(ActionIDType filter) const;
	QString filterInfo(ActionIDType filter) const;

	int getRequirements(const QAction*);
	RichParameterList initParameterList(const QAction*, const MeshDocument &);

	std::map<std::string, QVariant> applyFilter(const QAction* action, const RichParameterList & /*parent*/, MeshDocument &md, unsigned int& postConditionMask, vcg::CallBackPos * cb);
	int postCondition(const QAction *action) const;
	FilterClass getClass(const QAction*) const;
	FilterArity filterArity(const QAction* act) const;
private:
	void initParameterSetForFractalDisplacement (const QAction*, const MeshDocument &, RichParameterList &);
	void initParameterSetForCratersGeneration   (const MeshDocument &md, RichParameterList &par);

	enum {CR_FRACTAL_TERRAIN, FP_FRACTAL_MESH, FP_CRATERS};
};

#endif
