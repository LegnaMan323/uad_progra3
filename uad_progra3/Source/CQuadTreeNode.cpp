#include "../Include/CQuadTreeNode.h"

CQuadTreeNode::CQuadTreeNode(CHexgridCell *cellsedgesquad, CVector3 * Nedges)
{
	cout << "Constructor: QuadTreeNode" << endl;
	for (int i = 0; i < VCells.size; i++)
	{
		VCells.at(i);
	}

}

CQuadTreeNode::~CQuadTreeNode()
{

}

void CQuadTreeNode::subdivide(CHexgridCell *CellLimit)
{


}

void CQuadTreeNode::QTNRender()
{

}

