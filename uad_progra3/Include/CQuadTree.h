#pragma once

#include "CQuadTreeNode.h"
#include "CHexGrid.h"

class CQuadTree
{
private:
	CQuadTreeNode * m_QRoot;
	CHexgridCell * m_HQgrid;
	CVector3 *rQEdges;

	int subLimit;

public:
	
	CQuadTree();

	~CQuadTree();

	void BuildQuadTree(CHexgridCell *HexGrid);

	void QTRender();


};