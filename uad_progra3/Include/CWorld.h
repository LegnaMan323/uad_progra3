#pragma once
#include "CHexGrid.h"
#include "CQuadTree.h"

class CWorld
{
public:
	CWorld();
	~CWorld();
	bool initialize(COpenGLRenderer * renderer);
	void render();
private:
	CHexGrid * m_HexGrid;
	COpenGLRenderer* m_renderer;
};