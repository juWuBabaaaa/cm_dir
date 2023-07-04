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

 $Log$
 Revision 1.1  2008/02/02 13:36:09  gianpaolopalma
 Defined X3D plugin interface

 
 *****************************************************************************/
#ifndef IOX3D_H
#define IOX3D_H

#include <QObject>

#include <common/plugins/interfaces/io_plugin.h>
#include <common/ml_document/mesh_model.h>

class IoX3DPlugin : public QObject, public IOPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(IO_PLUGIN_IID)
	Q_INTERFACES(IOPlugin)


public:
	QString pluginName() const;
	std::list<FileFormat> importFormats() const;
	std::list<FileFormat> exportFormats() const;

	virtual void exportMaskCapability(const QString &format, int &capability, int &defaultBits) const;

	void open(const QString &formatName, const QString &fileName, MeshModel &m, int& mask, const RichParameterList &, vcg::CallBackPos *cb=0);
	void save(const QString &formatName, const QString &fileName, MeshModel &m, const int mask, const RichParameterList &, vcg::CallBackPos *cb);
};

#endif
