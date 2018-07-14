#pragma once

#ifndef CHEXGRIDCELL
#define CHEXGRIDCELL

#define GRAD_RAD 0.01745329251

#include "../Include/CVector3.h"
#include <iostream>

using namespace std;


class CHexgridCell
{
private:

	unsigned int *graphicMemoryObjectID;

	CVector3 m_center;
	CVector3 m_vertex[6];


public:

	const float sideSize = 1;
	const float hexTHight = (sqrt(3)*sideSize / 2);
	const float angrad = GRAD_RAD;
//	const float iDiameter = sideSize * 2; //

	CHexgridCell(float x, float y, float sSize);
	CHexgridCell * HexCell;
	~CHexgridCell();

	CVector3 getCenter();
	CVector3 getPonits(int ponit);
	void getVertexes(float * pVertex);
	unsigned int * getGraphicMemoryObjectId();

};

#endif //!CHEXGRIDCELL