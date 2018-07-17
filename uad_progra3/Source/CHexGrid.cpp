
#include "..\Include\CHexGrid.h"

CHexGrid::CHexGrid() : m_gridShaderProgramID(0), m_vertexArrayObjectID(0), m_verticesRaw(0)
{
	cout << "Constructor: HexGrid" << endl;
}


void CHexGrid::reset()
{

	if (m_vertexIndices != NULL)
	{
		delete[] m_vertexIndices;
		m_vertexIndices = NULL;
	}
	
	if (m_verticesRaw != NULL)
	{
		delete[] m_verticesRaw;
		m_verticesRaw = NULL;
	}

	m_numTotalVertices = 0;
	m_Initialized = false;
	m_graphicsMemoryObjectId = 0;
	m_shaderProgramId = 0;
}
