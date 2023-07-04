/*****************************************************************************
 * MeshLab                                                           o o     *
 * A versatile mesh processing toolbox                             o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2007-2021                                           \/)\/    *
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
#ifndef FILTER_UNSHARP_PLUGIN_H
#define FILTER_UNSHARP_PLUGIN_H

#include <QObject>
#include <common/plugins/interfaces/filter_plugin.h>

class FilterUnsharp : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum {
		FP_CREASE_CUT,
		FP_LAPLACIAN_SMOOTH,
		//FP_DIRECTIONAL_PRESERVATION_STORE,
		FP_DIRECTIONAL_PRESERVATION_BLEND,
		FP_DEPTH_SMOOTH,
		FP_HC_LAPLACIAN_SMOOTH,
		FP_SD_LAPLACIAN_SMOOTH,
		FP_TWO_STEP_SMOOTH,
		FP_TAUBIN_SMOOTH,
		FP_FACE_NORMAL_SMOOTHING,
		FP_FACE_NORMAL_NORMALIZE,
		FP_VERTEX_NORMAL_NORMALIZE,
		FP_VERTEX_QUALITY_SMOOTHING,
		FP_UNSHARP_NORMAL,
		FP_UNSHARP_GEOMETRY,
		FP_UNSHARP_QUALITY,
		FP_UNSHARP_VERTEX_COLOR,
		FP_UNSHARP_FACE_COLOR,
		FP_RECOMPUTE_VERTEX_NORMAL,
		FP_RECOMPUTE_FACE_NORMAL,
		FP_RECOMPUTE_QUADFACE_NORMAL,
		FP_LINEAR_MORPH,
		FP_SCALAR_HARMONIC_FIELD
	};

	FilterUnsharp();
	~FilterUnsharp();

	QString                         pluginName() const;
	QString                         pythonFilterName(ActionIDType f) const;
	QString                         filterName(ActionIDType filter) const;
	QString                         filterInfo(ActionIDType filter) const;
	FilterClass                     getClass(const QAction*) const;
	int                             getRequirements(const QAction*);
	std::map<std::string, QVariant> applyFilter(
		const QAction*           action,
		const RichParameterList& parameters,
		MeshDocument&            md,
		unsigned int&            postConditionMask,
		vcg::CallBackPos*        cb);
	RichParameterList initParameterList(const QAction* action, const MeshDocument& /*m*/);
	int               postCondition(const QAction*) const;
	int               getPreConditions(const QAction*) const;
	FilterArity       filterArity(const QAction* filter) const;
};

#endif // FILTER_UNSHARP_PLUGIN_H
