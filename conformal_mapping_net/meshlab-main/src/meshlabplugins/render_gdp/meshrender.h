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

#ifndef SHADERRENDERPLUGIN_H
#define SHADERRENDERPLUGIN_H

#include <GL/glew.h>
#include <common/plugins/interfaces/render_plugin.h>
#include "textfile.h"
#include "shaderStructs.h"
#include "shaderDialog.h"


class MeshShaderRenderPlugin : public QObject, public RenderPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(RENDER_PLUGIN_IID)
	Q_INTERFACES(RenderPlugin)
public:

	MeshShaderRenderPlugin();
	virtual ~MeshShaderRenderPlugin() {}

	QString pluginName() const;

	QList<QAction *> actions();

	bool isSupported() { return supported; }
	void refreshActions();

	void init(QAction *, MeshDocument &, MLSceneGLSharedDataContext::PerMeshRenderingDataMap& , GLArea *);
	void render(QAction *, MeshDocument &, MLSceneGLSharedDataContext::PerMeshRenderingDataMap&, GLArea *);
	void finalize(QAction*, MeshDocument*, GLArea*);
	
private:
	GLhandleARB v;
	GLhandleARB f;

	std::map<QString, ShaderInfo> shaders;

	bool supported;
	QList <QAction *> actionList;

	ShaderDialog *sDialog;
	
	void initActionList();
	void loadShaders(const QDir& shadersDir);
	QAction* loadGDPDoc(const QDomElement& root, const QDir& shadersDir, const QString& fileName);
};

#endif

