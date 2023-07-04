/*****************************************************************************
 * MeshLab                                                           o o     *
 * A versatile mesh processing toolbox                             o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2005-2021                                           \/)\/    *
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

#ifndef __CLEAN_FILTER_H__
#define __CLEAN_FILTER_H__

#include <QObject>
#include <common/plugins/interfaces/filter_plugin.h>

class CleanFilter : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum {
		FP_BALL_PIVOTING,
		FP_REMOVE_ISOLATED_COMPLEXITY,
		FP_REMOVE_ISOLATED_DIAMETER,
		FP_REMOVE_WRT_Q,
		FP_REMOVE_TVERTEX,
		FP_SNAP_MISMATCHED_BORDER,
		FP_REMOVE_FOLD_FACE,
		FP_REMOVE_DUPLICATE_FACE,
		FP_REPAIR_NON_MANIF_EDGE,
		FP_REMOVE_NON_MANIF_VERT,
		FP_REMOVE_UNREFERENCED_VERTEX,
		FP_REMOVE_DUPLICATED_VERTEX,
		FP_REMOVE_FACE_ZERO_AREA,
		FP_MERGE_CLOSE_VERTEX,
		FP_MERGE_WEDGE_TEX
	};

	CleanFilter();
	~CleanFilter();

	QString pluginName() const;
	QString filterName(ActionIDType filter) const;
	QString pythonFilterName(ActionIDType f) const;
	QString filterInfo(ActionIDType filter) const;

	FilterClass       getClass(const QAction*) const;
	int               getRequirements(const QAction*);
	int               postCondition(const QAction*) const;
	int               getPreConditions(const QAction*) const { return MeshModel::MM_NONE; }
	RichParameterList initParameterList(const QAction*, const MeshDocument& /*m*/);
	std::map<std::string, QVariant> applyFilter(
		const QAction* action,
		const RichParameterList& /*parent*/,
		MeshDocument&     md,
		unsigned int&     postConditionMask,
		vcg::CallBackPos* cb);
	FilterArity filterArity(const QAction*) const { return SINGLE_MESH; }
};

#endif
