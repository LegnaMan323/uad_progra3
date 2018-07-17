#pragma once

#ifndef CHEXGRID
#define CHEXGRID

#include <iostream>
#include <vector>
#include "../Include/CVector3.h"
#include "COpenGLRenderer.h"
#include "CWideStringHelper.h"
#include "Globals.h"
#include "CHexgridCell.h"
#include <string>
#define HEXGRIDSIZE 4
using namespace std;




class CHexGrid
{
private:


	const float sideSize = 1;
	const float hexHight = (sqrt(3)*sideSize);
	const float hexWidth = (2 * sideSize);
	//The horizontal distance between adjacent hexagon centers is w * 3 / 4. The vertical distance between adjacent hexagon centers is h.
	const float adjHorDist = hexWidth * (3 / 4);
	const float adjVerDist = hexHight; // delete this bruh
	CHexgridCell *m_HexGridLayout[HEXGRIDSIZE][HEXGRIDSIZE];

	unsigned int m_gridShaderProgramID;
	unsigned int m_vertexArrayObjectID;

	unsigned short *m_vertexIndices;                                                                
                    
	float *m_verticesRaw;                                         

	int m_numTotalVertices = (HEXGRIDSIZE*HEXGRIDSIZE)*5;

	void reset();


public:


	CHexGrid();
	~CHexGrid();

	void createHexGridorso();

	unsigned int* getShaderProgramId();
	unsigned int* getVertexArrayObjectID();


	bool Inicializer(COpenGLRenderer *openGLRenderer);

	int getNumIndices();

	CVector3 getPointInfogrido(int x, int y, int point);

};

#endif //!CHEXGRIDCELL