/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
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

#ifndef FILTER_MUTUALINFO_H
#define FILTER_MUTUALINFO_H

#include <QObject>

#include <common/plugins/interfaces/filter_plugin.h>
#include "alignset.h"

class FilterMutualInfoPlugin : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:

	enum {FP_IMAGE_MUTUALINFO} ;

	FilterMutualInfoPlugin();

	QString pluginName() const;

	QString filterName(ActionIDType filter) const;
	QString pythonFilterName(ActionIDType f) const;
	QString filterInfo(ActionIDType filter) const;
	FilterClass getClass(const QAction* a) const;
	bool requiresGLContext(const QAction* action) const;
	FilterArity filterArity(const QAction*) const;
	RichParameterList initParameterList(const QAction*, const MeshDocument &);
	std::map<std::string, QVariant> applyFilter(
			const QAction* action,
			const RichParameterList & parameters,
			MeshDocument &md,
			unsigned int& postConditionMask,
			vcg::CallBackPos * cb);
	int postCondition(const QAction*) const;
private:
	AlignSet align;

	//mutualInfo
	void imageMutualInfoAlign(
			MeshDocument &md,
			int rendmode,
			bool estimateFocal,
			bool fine,
			Scalarm expectedVariance,
			Scalarm tolerance,
			int numIterations,
			int backGroundWeight,
			Shotm shot);

	bool initGLMutualInfo();
};


#endif
