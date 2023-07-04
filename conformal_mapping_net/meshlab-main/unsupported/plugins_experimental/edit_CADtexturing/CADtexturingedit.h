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

#ifndef CADtexturingEDITPLUGIN_H
#define CADtexturingEDITPLUGIN_H

#include <QObject>
#include <meshlab/glarea.h>
#include <common/interfaces.h>
#include "CADtexturingControl.h"
#include <wrap/gl/trimesh.h>

class CADtexturingEditPlugin : public QObject, public MeshEditInterface
{
	Q_OBJECT
	Q_INTERFACES(MeshEditInterface)
		
public:
    CADtexturingEditPlugin();
    virtual ~CADtexturingEditPlugin() {}

    static const QString Info();

    bool StartEdit(MeshModel &/*m*/, GLArea * /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
    void EndEdit(MeshModel &/*m*/, GLArea * /*parent*/, MLSceneGLSharedDataContext* /*cont*/);
    void Decorate(MeshModel &/*m*/, GLArea * /*parent*/, QPainter *p);
    void Decorate (MeshModel &/*m*/, GLArea * ){};
    void mousePressEvent(QMouseEvent *, MeshModel &, GLArea * ) {};
    void mouseMoveEvent(QMouseEvent *, MeshModel &, GLArea * ) {};
    void mouseReleaseEvent(QMouseEvent *event, MeshModel &/*m*/, GLArea * );
	void keyReleaseEvent(QKeyEvent *, MeshModel &, GLArea *);
	void ComputeNearFar(const vcg::Shotf &  s, float & near, float & far);

	void renderEdges(GLArea *gla);
	vcg::GlTrimesh<CMeshO> drawer;

private:
	bool drawEdgesTrigger, saveRenderingTrigger;
	MeshModel * meshmodel;
	QDockWidget* dock;
	CADtexturingControl * control;
	GLArea * glarea;
signals:
	void suspendEditToggle();

	public slots:
	void on_renderEdges(int);
	void on_saverendering();
};

#endif
