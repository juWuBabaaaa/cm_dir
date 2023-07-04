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
#ifndef EXTRAIOPLUGIN_H
#define EXTRAIOPLUGIN_H

#include <QObject>
#include <QStringList>
#include <QString>

#include <common/plugins/interfaces/io_plugin.h>

namespace vcg{
namespace tri {
namespace io {
class _3dsInfo;
}
}
}
class Lib3dsFile;
class Lib3dsNode;

class ExtraMeshIOPlugin : public QObject, public IOPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(IO_PLUGIN_IID)
	Q_INTERFACES(IOPlugin)

public:
	QString pluginName() const;

	std::list<FileFormat> importFormats() const;
	std::list<FileFormat> exportFormats() const;


	void exportMaskCapability(const QString& format, int &capability, int &defaultBits) const;

	RichParameterList initPreOpenParameter(
			const QString& format) const;

	unsigned int numberMeshesContainedInFile(
			const QString& format,
			const QString& fileName,
			const RichParameterList& preParams) const;

	void open(
			const QString &formatName,
			const QString &fileName,
			MeshModel& m,
			int& mask,
			const RichParameterList& params,
			vcg::CallBackPos *cb=0);

	void open(
			const QString &formatName,
			const QString &fileName,
			const std::list<MeshModel *>& meshList,
			std::list<int>& maskList,
			const RichParameterList& params,
			vcg::CallBackPos *cb=0);

	void save(
			const QString &formatName,
			const QString &fileName,
			MeshModel &m,
			const int mask,
			const RichParameterList &,
			vcg::CallBackPos *cb=0);

private:
	void loadFromNode(MeshModel& mm, int& mask, vcg::tri::io::_3dsInfo& info, Lib3dsFile *file, Lib3dsNode *p);
};

#endif
