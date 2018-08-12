
#include "..\Include\CHexGrid.h"


CHexGrid::CHexGrid() : m_gridShaderProgramID(0), m_vertexArrayObjectID(0), m_verticesRaw(NULL)
{
	cout << "Constructor: HexGrid" << endl;
}

CHexGrid::~CHexGrid()
{
	cout << "Destructor: HexGrid" << endl;
	reset();
}


void CHexGrid::reset()
{
	/*
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


	m_gridShaderProgramID = 0;
	m_vertexArrayObjectID = 0;
	*/
}

void CHexGrid::createHexGrid()
{

	int vertexIT = 0;
	int vertexIndexIT = 0;
	m_verticesRaw = new float[HEXGRIDSIZE * HEXGRIDSIZE * 3 * 6];
	m_HexGridLayout[0][0] = new CHexgridCell(0, 0, sideSize);
	int singleHexIndices[] = { 0,1,2,2,0,3,3,4,5,5,3,0};
	
	

	float nCenterX = 0;
	float nCenterY = 0;


	for (int i = 0; i < HEXGRIDSIZE; i++)
	{
		for (int j = 0; j < HEXGRIDSIZE; j++)
		{
			if (flatgrid)
			{

				//	cout << "i" << i << endl;
				//	cout << "j" << j << endl;
			
				nCenterX = j * (hexWidth * 3 / 4);
				if (j % 2 == 0)
				{
					nCenterY = i * hexHight;
				}
				else
				{
					nCenterY = i * hexHight + hexHight / 2;
				}

				m_HexGridLayout[i][j] = new CHexgridCell(nCenterX, nCenterY, sideSize);
				//	m_HexGridLayout[i][j] = new CHexgridCell(nCenterY, nCenterX, sideSize);
			}
			else
			{

				//	cout << "i" << i << endl;
				//	cout << "j" << j << endl;
			
				
				nCenterY = i * (hexWidth * 3 / 4);
				if (i % 2 == 0)
				{
					nCenterX = j * (hexHight);
				}
				else
				{
					nCenterX = j * (hexHight) + (hexHight/2);
				}

				m_HexGridLayout[i][j] = new CHexgridCell(nCenterX, nCenterY, sideSize);
				//	m_HexGridLayout[i][j] = new CHexgridCell(nCenterY, nCenterX, sideSize);
			}

				for (int k = 0; k < 6; k++)
				{
					m_verticesRaw[vertexIT++] = m_HexGridLayout[i][j]->m_vertex[k].getX();

					m_verticesRaw[vertexIT++] = m_HexGridLayout[i][j]->m_vertex[k].getY();

					m_verticesRaw[vertexIT++] = m_HexGridLayout[i][j]->m_vertex[k].getZ();

				}

				for (int l = 0; l < 12; l++)
				{
					m_vertexIndices[vertexIndexIT++] = (i * HEXGRIDSIZE * 6 + j * 6 + singleHexIndices[l]);
				}
			
		}
	}
}








bool CHexGrid::Inicializer(COpenGLRenderer *openGLRenderer)
{
	createHexGrid();

	std::wstring wresourceFilenameVS;
	std::wstring wresourceFilenameFS;
	std::string resourceFilenameVS;
	std::string resourceFilenameFS;



	// If resource files cannot be found, return
	if (!CWideStringHelper::GetResourceFullPath(VERTEX_SHADER_WIREFRAME, wresourceFilenameVS, resourceFilenameVS) ||
		!CWideStringHelper::GetResourceFullPath(FRAGMENT_SHADER_WIREFRAME, wresourceFilenameFS, resourceFilenameFS))
	{
		cout << "ERROR: Unable to find one or more resources: " << endl;
		cout << "  " << VERTEX_SHADER_WIREFRAME << endl;
		cout << "  " << FRAGMENT_SHADER_WIREFRAME << endl;
		return false;
	}


	openGLRenderer->createShaderProgram(&m_gridShaderProgramID, resourceFilenameVS.c_str(), resourceFilenameFS.c_str());
	openGLRenderer->allocateGraphicsMemoryForObject(&m_gridShaderProgramID , &m_vertexArrayObjectID, m_verticesRaw, HEXGRIDSIZE*HEXGRIDSIZE * 6, m_vertexIndices, HEXGRIDSIZE*HEXGRIDSIZE * 12);

	return true;
}

unsigned int* CHexGrid::getShaderProgramId()
{
	return &m_gridShaderProgramID;
}

unsigned int* CHexGrid::getVertexArrayObjectID()
{
	return &m_vertexArrayObjectID;
}