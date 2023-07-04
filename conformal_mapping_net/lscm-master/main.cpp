// Least squares conformal mapping
//
// Author   : Mi, Liang
// Email    : icemiliang@gmail.com
// Date     : July 31st 2020
// License  : MIT

#include <cmath>
#include "Mesh.h"
#include "FormTrait.h"
#include "LSCM.h"
#include <iostream>

using namespace MeshLib;

int main(int argc, char * argv[]) {
	std::cout << "--> Reading mesh..." << std::endl;
	Mesh mesh;
	mesh.read_obj(argv[1]);
	std::cout << "numVertices: " << mesh.numVertices() << std::endl;
	std::cout << "numEdges: " << mesh.numEdges() << std::endl;


	FormTrait traits(&mesh);

	std::cout << "--> Computing conformal map..." << std::endl;
	LSCM lscm(&mesh);
    lscm.project();

	std::cout << "--> Writing mesh..." << std::endl;
	std::cout << "numVertices: " << mesh.numVertices() << std::endl;
	std::cout << "numEdges: " << mesh.numEdges() << std::endl;


	mesh.write_obj(argv[2]);
	return 0;
}
