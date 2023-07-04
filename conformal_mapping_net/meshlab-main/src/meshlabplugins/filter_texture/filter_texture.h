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

#ifndef _FILTER_TEXTURE_H
#define _FILTER_TEXTURE_H


#include <QObject>
#include <QTime>

#include <common/plugins/interfaces/filter_plugin.h>
#include <vcg/complex/append.h>
#include <vcg/complex/algorithms/attribute_seam.h>
#include <vcg/complex/algorithms/point_sampling.h>
#include <vcg/space/triangle2.h>

class FilterTexturePlugin : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum {
		FP_VORONOI_ATLAS,
		FP_UV_WEDGE_TO_VERTEX,
		FP_UV_VERTEX_TO_WEDGE,
		FP_BASIC_TRIANGLE_MAPPING,
		FP_PLANAR_MAPPING,
		FP_SET_TEXTURE,
		FP_COLOR_TO_TEXTURE,
		FP_TRANSFER_TO_TEXTURE,
		FP_TEX_TO_VCOLOR_TRANSFER
	};

	FilterTexturePlugin();

	QString pluginName() const;
	QString filterName(ActionIDType filter) const;
	QString pythonFilterName(ActionIDType f) const;
	QString filterInfo(ActionIDType filter) const;
	RichParameterList initParameterList(const QAction*, const MeshDocument &/*m*/);
	std::map<std::string, QVariant> applyFilter(
			const QAction* action,
			const RichParameterList & parameters,
			MeshDocument &md,
			unsigned int& postConditionMask,
			vcg::CallBackPos * cb);
	int getRequirements(const QAction*);
	int getPreConditions(const QAction*) const;
	int postCondition(const QAction* ) const;
	FilterClass getClass(const QAction *a) const;
	FilterArity filterArity(const QAction* filter) const;
private:
	void transferToTexture(MeshDocument &md, const RichParameterList & parameters, vcg::CallBackPos * cb);
};

#endif
