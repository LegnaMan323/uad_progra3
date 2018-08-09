#pragma once

#ifndef CQUADTREENODE
#define CQUADTREENODE


#include "../Include/CVector3.h"
#include "CHexgridCell.h"
#include <iostream>
#include <vector>
using namespace std;




class CQuadTreeNode
{
private:

	CVector3 m_Corners[4];
	vector<CHexgridCell> m_VCellsinQuad;
	int m_CellLimits;

	CQuadTreeNode*Nodes[4];
	void render();
	void Subdivide(/*cells*/);
	{

	}


public:

	CQuadTreeNode();
	~CQuadTreeNode();


};

#endif //!CQUADTREENODE