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

#ifndef FILTER_FUNC_PLUGIN_H
#define FILTER_FUNC_PLUGIN_H

#include <QObject>

#include <common/plugins/interfaces/filter_plugin.h>

#include "filter_refine.h"

class FilterFunctionPlugin : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

protected:
	double x, y, z, nx, ny, nz, r, g, b, a, q, vtu, vtv, vsel;
	double x0, y0, z0, x1, y1, z1, x2, y2, z2, nx0, ny0, nz0, nx1, ny1, nz1, nx2, ny2, nz2, r0, g0,
		b0, a0, r1, g1, b1, a1, r2, g2, b2, a2, q0, q1, q2, wtu0, wtv0, wtu1, wtv1, wtu2, wtv2,
		vsel0, vsel1, vsel2;
	double                   fr, fg, fb, fa, fnx, fny, fnz, fq, fsel;
	double                   v, f, v0i, v1i, v2i, ti;
	std::vector<std::string> v_attrNames;  // names of the <float> per vertex attributes
	std::vector<double>      v_attrValue;  // values of the <Scalarm> per vertex attributes
	std::vector<std::string> v3_attrNames; // names of the <Point3f> per vertex attributes There are
										   // 3x (one foreach coord _x, _y, _z)
	std::vector<double> v3_attrValue; // values of the <Point3m> per vertex attributes. There are 3x
									  // (one foreach coord _x, _y, _z)
	std::vector<std::string>                               f_attrNames;
	std::vector<double>                                    f_attrValue;
	std::vector<CMeshO::PerVertexAttributeHandle<Scalarm>> v_handlers;
	std::vector<CMeshO::PerVertexAttributeHandle<Point3m>> v3_handlers;
	std::vector<CMeshO::PerFaceAttributeHandle<Scalarm>>   f_handlers;
	QString                                                errorMsg;

public:
	enum {
		FF_VERT_SELECTION,
		FF_FACE_SELECTION,
		FF_GEOM_FUNC,
		FF_VERT_TEXTURE_FUNC,
		FF_WEDGE_TEXTURE_FUNC,
		FF_FACE_COLOR,
		FF_VERT_COLOR,
		FF_VERT_NORMAL,
		FF_VERT_QUALITY,
		FF_FACE_QUALITY,
		FF_DEF_VERT_SCALAR_ATTRIB,
		FF_DEF_FACE_SCALAR_ATTRIB,
		FF_DEF_VERT_POINT_ATTRIB,
		FF_DEF_FACE_POINT_ATTRIB,
		FF_GRID,
		FF_ISOSURFACE,
		FF_REFINE
	};

	FilterFunctionPlugin();
	~FilterFunctionPlugin();

	QString           pluginName() const;
	QString           pythonFilterName(ActionIDType f) const;
	QString           filterName(ActionIDType filter) const;
	QString           filterInfo(ActionIDType filter) const;
	FilterClass       getClass(const QAction*) const;
	int               postCondition(const QAction* action) const;
	RichParameterList initParameterList(const QAction*, const MeshModel& /*m*/);
	virtual int       getRequirements(const QAction*);

	std::map<std::string, QVariant> applyFilter(
		const QAction*           action,
		const RichParameterList& parameters,
		MeshDocument&            md,
		unsigned int&            postConditionMask,
		vcg::CallBackPos*        cb);
	FilterArity filterArity(const QAction* filter) const;

	void showParserError(const QString& s, mu::Parser::exception_type& e);
	void setAttributes(CMeshO::VertexIterator& vi, CMeshO& m);
	void setAttributes(CMeshO::FaceIterator& fi, CMeshO& m);
	void setPerVertexVariables(mu::Parser& p, CMeshO& m);
	void setPerFaceVariables(mu::Parser& p, CMeshO& m);
	void checkAttributeName(const std::string& name) const;
};

#endif
