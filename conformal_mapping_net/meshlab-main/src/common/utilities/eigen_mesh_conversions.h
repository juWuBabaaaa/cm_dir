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

#ifndef MESHLAB_EIGEN_MESH_CONVERSIONS_H
#define MESHLAB_EIGEN_MESH_CONVERSIONS_H

#include "../ml_document/cmesh.h"
#include <Eigen/Core>
#include <list>

typedef Eigen::Matrix<Scalarm, Eigen::Dynamic, 1>      EigenVectorXm;
typedef Eigen::Matrix<bool, Eigen::Dynamic, 1>         EigenVectorXb;
typedef Eigen::Matrix<unsigned int, Eigen::Dynamic, 1> EigenVectorXui;

typedef Eigen::Matrix<Scalarm, Eigen::Dynamic, 2> EigenMatrixX2m;
typedef Eigen::Matrix<Scalarm, Eigen::Dynamic, 3> EigenMatrixX3m;
typedef Eigen::Matrix<Scalarm, Eigen::Dynamic, 4> EigenMatrixX4m;

typedef Eigen::Matrix<Scalarm, Eigen::Dynamic, Eigen::Dynamic> EigenMatrixXm;

namespace meshlab {

// From eigen to CMeshO
CMeshO meshFromMatrices(
	const EigenMatrixX3m&   vertices,
	const Eigen::MatrixX3i& faces         = Eigen::MatrixX3i(),
	const Eigen::MatrixX2i& edges         = Eigen::MatrixX2i(),
	const EigenMatrixX3m&   vertexNormals = EigenMatrixX3m(),
	const EigenMatrixX3m&   faceNormals   = EigenMatrixX3m(),
	const EigenVectorXm&    vertexQuality = EigenVectorXm(),
	const EigenVectorXm&    faceQuality   = EigenVectorXm(),
	const EigenMatrixX4m&   vertexColor   = EigenMatrixX4m(),
	const EigenMatrixX4m&   faceColor     = EigenMatrixX4m());

// From eigen to polygonal CMeshO
CMeshO polyMeshFromMatrices(
	const EigenMatrixX3m&            vertices,
	const std::list<EigenVectorXui>& faces,
	const EigenMatrixX3m&            vertexNormals = EigenMatrixX3m(),
	const EigenMatrixX3m&            faceNormals   = EigenMatrixX3m(),
	const EigenVectorXm&             vertexQuality = EigenVectorXm(),
	const EigenVectorXm&             faceQuality   = EigenVectorXm(),
	const EigenMatrixX4m&            vertexColor   = EigenMatrixX4m(),
	const EigenMatrixX4m&            faceColor     = EigenMatrixX4m());

void addVertexScalarAttribute(
	CMeshO&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName);

void addFaceScalarAttribute(
	CMeshO&              mesh,
	const EigenVectorXm& attributeValues,
	const std::string&   attributeName);

void addVertexVectorAttribute(
	CMeshO&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName);

void addFaceVectorAttribute(
	CMeshO&               mesh,
	const EigenMatrixX3m& attributeValues,
	const std::string&    attributeName);

// From CMeshO to Eigen
EigenMatrixX3m            vertexMatrix(const CMeshO& mesh);
EigenMatrixX3m            transformedVertexMatrix(const CMeshO& mesh);
Eigen::MatrixX3i          faceMatrix(const CMeshO& mesh);
Eigen::MatrixX2i          edgeMatrix(const CMeshO& mesh);
std::list<EigenVectorXui> polygonalFaceList(const CMeshO& mesh);
EigenMatrixX3m            vertexNormalMatrix(const CMeshO& mesh);
EigenMatrixX3m            transformedVertexNormalMatrix(const CMeshO& mesh);
EigenMatrixX3m            faceNormalMatrix(const CMeshO& mesh);
EigenMatrixX3m            transformedFaceNormalMatrix(const CMeshO& mesh);
EigenMatrixX4m            vertexColorMatrix(const CMeshO& mesh);
EigenMatrixX4m            faceColorMatrix(const CMeshO& mesh);
EigenVectorXui            vertexColorArray(const CMeshO& mesh);
EigenVectorXui            faceColorArray(const CMeshO& mesh);
EigenVectorXm             vertexQualityArray(const CMeshO& mesh);
EigenVectorXm             faceQualityArray(const CMeshO& mesh);
EigenMatrixX2m            vertexTexCoordMatrix(const CMeshO& mesh);
EigenMatrixX2m            wedgeTexCoordMatrix(const CMeshO& mesh);
EigenVectorXb             vertexSelectionArray(const CMeshO& mesh);
EigenVectorXb             faceSelectionArray(const CMeshO& mesh);
EigenMatrixX3m            vertexCurvaturePD1Matrix(const CMeshO& mesh);
EigenMatrixX3m            vertexCurvaturePD2Matrix(const CMeshO& mesh);
EigenMatrixX3m            faceCurvaturePD1Matrix(const CMeshO& mesh);
EigenMatrixX3m            faceCurvaturePD2Matrix(const CMeshO& mesh);

Eigen::MatrixX3i faceFaceAdjacencyMatrix(const CMeshO& mesh);

EigenVectorXm  vertexScalarAttributeArray(const CMeshO& mesh, const std::string& attributeName);
EigenMatrixX3m vertexVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName);
EigenVectorXm  faceScalarAttributeArray(const CMeshO& mesh, const std::string& attributeName);
EigenMatrixX3m faceVectorAttributeMatrix(const CMeshO& mesh, const std::string& attributeName);
} // namespace meshlab

#endif // MESHLAB_EIGEN_MESH_CONVERSIONS_H
