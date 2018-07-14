#include "Include\CWorld.h"


CWorld::CWorld()
{
	m_pHexGrid = new CHexGrid();
}

CWorld::~CWorld()
{
}

bool CWorld::initialize(COpenGLRenderer* renderer)
{
	this->m_renderer = renderer;
	return m_pHexGrid->Inicializer(renderer);

}

void CWorld::render()
{
	float c[3] = { 255.0f, 160.0f, 16.0f }; // Color
	MathHelper::Matrix4 modelMatrix = MathHelper::ModelMatrix((float)0, CVector3(-8, -8, -17));
	//MthHelper::Matrix4 modelMatrix = MathHelper::ModelMatrix((float)totalDegreesRotatedRadians, m_objectPosition);
	m_renderer->renderWireframeObject(m_pHexGrid->getShaderProgramId(),
		m_pHexGrid->getVertexArrayObjectID(),
		4 * HEXGRIDSIZE*HEXGRIDSIZE, c,	&modelMatrix);
}