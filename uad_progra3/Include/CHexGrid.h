#pragma once

#ifndef CHEXGRID
#define CHEXGRID

#include <iostream>
#include "../Include/CVector3.h"
#include "COpenGLRenderer.h"
#include "CWideStringHelper.h"
#include "Globals.h"
#include "CHexgridCell.h"
#include <string>
#define HEXGRIDSIZE 5
using namespace std;




class CHexGrid
{
private:


	const float sideSize = 1;
	const float hexHight = sqrt(3)*(sideSize);
	const float hexWidth = (2 * sideSize);
	//The horizontal distance between adjacent hexagon centers is w * 3 / 4. The vertical distance between adjacent hexagon centers is h.
	const float adjHorDist = hexWidth * (3 / 4);
	const float adjVerDist = hexHight; // delete this bruh

	float *m_verticesRaw;


	CHexgridCell * m_HexGridLayout[HEXGRIDSIZE][HEXGRIDSIZE];

	unsigned int m_gridShaderProgramID;
	unsigned int m_vertexArrayObjectID;

	unsigned short m_vertexIndices[4 * 3 * HEXGRIDSIZE*HEXGRIDSIZE];
                    


	void reset();


public:




	CHexGrid();
	~CHexGrid();

	void createHexGrid();

	unsigned int* getShaderProgramId();
	unsigned int* getVertexArrayObjectID();
	


	bool Inicializer(COpenGLRenderer *openGLRenderer);




};

#endif //!CHEXGRIDCELL