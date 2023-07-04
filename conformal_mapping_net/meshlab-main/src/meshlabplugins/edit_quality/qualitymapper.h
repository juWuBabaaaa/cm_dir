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
/****************************************************************************
History
Revision 1.0 2008/02/20 Alessandro Maione, Federico Bellucci
FIRST RELEASE

****************************************************************************/

#ifndef MESHLAB_QUALITY_MAPPER_PLUGIN_H
#define MESHLAB_QUALITY_MAPPER_PLUGIN_H

#include <QObject>
#include <QAction>
#include <QList>

#include <common/plugins/interfaces/edit_plugin.h>
#include "qualitymapperdialog.h"

//This class defines the plugin interface
class QualityMapperPlugin : public QObject, public EditTool
{
	Q_OBJECT

private:
	QualityMapperDialog *_qualityMapperDialog;

public:
	QualityMapperPlugin(void);
	~QualityMapperPlugin(void) {};

	static const QString info();
	bool startEdit(MeshModel&, GLArea*, MLSceneGLSharedDataContext* cont);
	void endEdit(MeshModel&, GLArea*, MLSceneGLSharedDataContext* cont);
	void suggestedRenderingData(MeshModel &/*m*/, MLRenderingData& /*dt*/);
    //virtual void Decorate(MeshModel&, GLArea*);
    void mousePressEvent(QMouseEvent*, MeshModel&, GLArea*) {};
    void mouseMoveEvent(QMouseEvent*, MeshModel&, GLArea*) {};
    void mouseReleaseEvent(QMouseEvent *, MeshModel&, GLArea*){};

	QPoint cur;
	bool haveToPick;
};

#endif // MESHLAB_QUALITY_MAPPER_PLUGIN_H
