#include "..\Include\CWorld.h"

CWorld::CWorld()
{
	m_HexGrid = new CHexGrid();
}

CWorld::~CWorld()
{

}

bool CWorld::initialize(COpenGLRenderer* renderer)
{
	this->m_renderer = renderer;
	return m_HexGrid->Inicializer(m_renderer);

}

void CWorld::render()
{
	float HexColor[3] = { 1.0f, 1.0f, 1.0f }; // Color
	MathHelper::Matrix4 modelMatrix = MathHelper::ModelMatrix((float)0, CVector3(-8, -8, -17));

	m_renderer->renderWireframeObject(m_HexGrid->getShaderProgramId(),
		m_HexGrid->getVertexArrayObjectID(),
		4 * HEXGRIDSIZE*HEXGRIDSIZE, HexColor, &modelMatrix);
}