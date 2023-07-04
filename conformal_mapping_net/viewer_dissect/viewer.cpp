#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<GL/glut.h>
#include "viewer/arcball.h"                           /*  Arc Ball  Interface         */
#include "Mesh/TriangleSoup.h"
#include "bmp/RgbImage.h"

//compiling command
//g++ view_mesh.cpp -o view_mesh -lGL -lglut -lGLU -IMeshLib

using namespace MeshLib::TriangleSoup;

enum mesh_type{OBJ,M};


CTriangleMesh mesh;
CObject       object;

mesh_type current_mesh_type;

/* window width and height */
int win_width, win_height;
int gButton;
int startx,starty;
int shadeFlag   = 0 ;

/* rotation quaternion and translation vector for the object */
MeshLib::CQrot       ObjRot(0,0,1,0);
MeshLib::CPoint      ObjTrans(0,0,0);
/* arcball object */
MeshLib::CArcball arcball;

/* geometry flag */
int geometryFlag = 0;

/* texture flag */
int textureFlag =  2; 
/* texture id and image */
GLuint texName;
RgbImage image;

void normalize( CObject & object );
void compute_normal( CObject & object );


int main(int argc, char* argv[]) {

	std::string name( argv[1] );

	unsigned pos = name.find_last_of(".");
	std::string type  = name.substr( pos +1 );

	if( type == "obj" )
	{
		std::cout << argv[1] << std::endl;
		object.read( argv[1] );
		normalize( object );
		compute_normal( object );
		// current_mesh_type = OBJ;
	}


	return 0;
}

void normalize( CObject & object )
{	
	std::cout << "points size: " << object.points().size() << std::endl;
	MeshLib::CPoint center(0,0,0);
	for( size_t i =
	 0; i < object.points().size(); i ++ )
	{
		center += object.points()[i];
	}
	center /= (double)(object.points().size());

	for( size_t i = 0; i < object.points().size(); i ++ )
	{
		object.points()[i] -= center;
	}

	double len = -1;

	for( size_t i = 0; i < object.points().size(); i ++ )
	{
		MeshLib::CPoint p = object.points()[i];
		for( int j = 0; j < 3; j ++ )
		{
			len = (len > p[j])? len: fabs(p[j]);
		}
	}

	for( size_t i = 0; i < object.points().size(); i ++ )
	{
		object.points()[i] /= len;
	}

}

void compute_normal( CObject & object )
{	
	std::cout << "faces: " << object.faces().size() << std::endl;
	for( size_t i = 0; i < object.faces().size(); i ++ )
	{
		CObjFace * pF = & object.faces()[i];

		MeshLib::CPoint p[3];
		for( int j = 0; j < 3; j ++ )
		{
			p[j] = object.points()[pF->m_v[j].m_ipt];
		}

		MeshLib::CPoint nor = (p[1]-p[0])^(p[2]-p[0]);
		pF->m_area = nor.norm();

		nor /= nor.norm();
		pF->m_normal = nor;
	}

	if( object.m_has_normal ) return;

	object.normals().resize( object.points().size() );

	for( size_t i = 0; i < object.faces().size(); i ++ )
	{
		CObjFace * pF = &object.faces()[i];

		for( int j = 0; j < 3; j ++ )
		{
			pF->m_v[j].m_inl = pF->m_v[j].m_ipt;
			object.normals()[pF->m_v[j].m_inl] += pF->m_normal * pF->m_area;
		}
	}

	for( size_t i = 0; i < object.normals().size(); i ++ )
	{
		object.normals()[i] /= object.normals()[i].norm();
	}

}

