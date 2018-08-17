#pragma once

#ifndef CHEXGRIDCELL
#define CHEXGRIDCELL

#define GRAD_RAD 0.01745329251
#define THIRTY_GRAD_RAD 0.523599
//#define TEST_PIE arctan(1)*4

#include "../Include/CVector3.h"
#include <iostream>

using namespace std; 


class CHexgridCell
{
private:




public:
	CVector3 m_center;
	bool flathex = true;
	CVector3 m_vertex[6];
	const float sideSize = 1;
	const float angrad = GRAD_RAD;
	const float thirtyGrad = THIRTY_GRAD_RAD;

	CHexgridCell(float x, float y, float sSize, int cellID);
	CHexgridCell * HexCell;
	~CHexgridCell();
	CVector3 getCenter();

};

#endif //!CHEXGRIDCELL