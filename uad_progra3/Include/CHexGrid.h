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

	CHexgridCell *m_HexGridLayout[HEXGRIDSIZE][HEXGRIDSIZE];

	unsigned int m_gridShaderProgramID;
	unsigned int m_vertexArrayObjectID();



public:


	CHexGrid();
	~CHexGrid();

	void createHexGrid();

	unsigned int* getShaderProgramId();
	unsigned int* getVertexArrayObjectID();


	bool Inicializer(COpenGLRenderer *openGLRenderer);

	int getNumIndices();

	CVector3 getPointInfogrido(int x, int y, int point);

};

#endif //!CHEXGRIDCELL