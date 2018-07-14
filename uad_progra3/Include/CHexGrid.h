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
using namespace std;



class CHexGrid
{
private:


	const float sideSize = 1;
	const float hexHight = (sqrt(3)*sideSize);
	const float hexWidth = (2 * sideSize);

	unsigned int gridShaderProgramID;



public:


	CHexGrid();
	~CHexGrid();

	bool Inicializer(COpenGLRenderer *openGLRenderer);

	unsigned int* getShaderProgramId();
	int getNumIndices();

	CVector3 getPointInfogrido(int x, int y, int point);

};

#endif //!CHEXGRIDCELL