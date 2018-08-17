#pragma once

#include <iostream>
#include "CVector3.h"
#include <vector>
#include "CHexgridCell.h"


using namespace std;

class CQuadTreeNode
{
private:
	CVector3 rEdges[4];
	vector<CHexgridCell> VCells;
	int m_CellLimits;
	CQuadTreeNode *Nodes[4];




	


public:

	
	CQuadTreeNode(CHexgridCell *cellsedgesquad, CVector3 *	Nedges);
	~CQuadTreeNode();
	void subdivide(CHexgridCell *CellLimit);
	
	void QTNRender();


};