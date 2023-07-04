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

#ifndef FILTERCOLORPROCPLUGIN_H
#define FILTERCOLORPROCPLUGIN_H

#include <QObject>
#include <common/plugins/interfaces/filter_plugin.h>


class FilterColorProc : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum {
		CP_FILLING,
		CP_THRESHOLDING,
		CP_CONTR_BRIGHT,
		CP_GAMMA,
		CP_LEVELS,
		CP_INVERT,
		CP_COLOURISATION,
		CP_DESATURATION,
		CP_WHITE_BAL,
		CP_EQUALIZE,
		CP_PERLIN_COLOR,
		CP_COLOR_NOISE,
		CP_SCATTER_PER_MESH,
		CP_CLAMP_QUALITY,
		CP_SATURATE_QUALITY,
		CP_MAP_VQUALITY_INTO_COLOR,
		CP_MAP_FQUALITY_INTO_COLOR,
		CP_DISCRETE_CURVATURE,
		CP_TRIANGLE_QUALITY,
		CP_VERTEX_SMOOTH,
		CP_FACE_SMOOTH,
		CP_FACE_TO_VERTEX,
		CP_TEXTURE_TO_VERTEX,
		CP_VERTEX_TO_FACE,
		CP_MESH_TO_FACE,
		CP_RANDOM_FACE,
		CP_RANDOM_CONNECTED_COMPONENT,
		CP_VERTEX_TO_FACE_QUALITY,
		CP_FACE_TO_VERTEX_QUALITY,
	};

	FilterColorProc();
	~FilterColorProc();

	QString pluginName() const;
	virtual FilterClass getClass(const QAction*) const;
	QString pythonFilterName(ActionIDType f) const;
	virtual QString filterName(ActionIDType filter) const;
	virtual QString filterInfo(ActionIDType filter) const;

	virtual int getRequirements(const QAction*);

	virtual RichParameterList initParameterList(const QAction*, const MeshDocument&);
	std::map<std::string, QVariant> applyFilter(const QAction* action, const RichParameterList & /*parent*/, MeshDocument &md, unsigned int& postConditionMask, vcg::CallBackPos * cb);
	int postCondition(const QAction* filter) const;
	int getPreConditions(const QAction *) const;
	FilterArity filterArity(const QAction *act) const;
};
#endif
