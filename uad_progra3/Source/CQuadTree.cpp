#include "../Include/CQuadTree.h"

CQuadTree::CQuadTree()
{
	cout << "Constructor: QuadTree " << endl;
}

CQuadTree::~CQuadTree()
{
	cout << "Destructor: QuadTree " << endl;
}

	
void CQuadTree::BuildQuadTree(CHexgridCell *HexGrid)
{
	m_HQgrid = HexGrid;
	m_QRoot = new CQuadTreeNode();

}

void CQuadTree::QTRender()
{

}
