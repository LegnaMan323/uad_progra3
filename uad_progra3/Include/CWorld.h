#pragma once
#include "CHexGrid.h"

class CWorld
{
public:
	CWorld();
	~CWorld();
	bool initialize(COpenGLRenderer * renderer);
	void render(CVector3 CamPosition);
private:
	CHexGrid * m_HexGrid;
	COpenGLRenderer* m_renderer;
};