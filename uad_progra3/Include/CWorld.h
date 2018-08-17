#pragma once
#include "CHexGrid.h"
#include "CQuadTree.h"




class CWorld
{
public:
	CWorld();
	~CWorld();
	bool initialize(COpenGLRenderer * renderer);
	void render(CVector3 CamPosition);

private:
	//CVector3 m_CamPosition;
	CHexGrid * m_HexGrid;
	COpenGLRenderer* m_renderer;
};