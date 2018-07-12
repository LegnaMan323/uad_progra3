#include "../stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "..\Include\CHexgridCell.h"


using namespace std;

#include "../Include/C3DModel.h"
#include "../Include/C3DModel_X.h"

C3DModel_X::C3DModel_X() : C3DModel(), m_currentVertex(0),
m_currentNormal(0), m_currentFace(0), m_currentUV(0)
{
	cout << "Constructor: C3DModel_X" << endl;
}

C3DModel_X::~C3DModel_X()
{
	cout << "Destructor: C3DModel_X" << endl;
	reset();
}

void C3DModel_X::reset()
{

	if (m_vertexIndices != NULL)
		{
		delete[] m_vertexIndices;
		m_vertexIndices = NULL;
		}
	if (m_normalIndices != NULL)
		{
		delete[] m_normalIndices;
		m_normalIndices = NULL;
		}
	if (m_UVindices != NULL)
		 {
		delete[] m_UVindices;
		m_UVindices = NULL;
		}
	if (m_verticesRaw != NULL)
		 {
		delete[] m_verticesRaw;
		m_verticesRaw = NULL;
		}
	if (m_normalsRaw != NULL)
		 {
		delete[] m_normalsRaw;
		m_normalsRaw = NULL;
		}
	if (m_uvCoordsRaw != NULL)
		 {
		delete[] m_uvCoordsRaw;
		m_uvCoordsRaw = NULL;
		}
	m_numVertices = 0;
	m_numNormals = 0;
	m_numUVCoords = 0;
	m_numFaces = 0;
	
	m_Initialized = false;
	
	m_graphicsMemoryObjectId = 0;
	m_shaderProgramId = 0;
}

bool C3DModel_X::loadFromFile(const char * const filename)
{
	bool readFileOk = false;

	reset();

	readFileOk = readXFile(filename);

	cout << "Finished reading 3D model" << endl;
	cout << "Vertices: " << m_numVertices << endl;
	cout << "Normals: " << m_numNormals << endl;
	cout << "UVCoords: " << m_numUVCoords << endl;
	cout << "Faces: " << m_numFaces << endl;


	if (readFileOk)
	{
		if (m_numVertices >= 65535 || m_numNormals >= 65356 || m_numUVCoords >= 65535)
		{
			cout << "Error: object cannot have more than 65535 vertices" << endl;
			cout << "Object attempted to load has: " << m_numVertices << " vertices" << endl;
			return false;
		}


		if (m_numNormals == 0)
		{
			m_modelHasNormals = false;
			m_numNormals = m_numVertices;
		}
		else
		{
			m_modelHasNormals = true;
		}

		if (m_numUVCoords == 0)
		{
			m_numUVCoords = m_numVertices;
			m_modelHasUVs = false;
		}
		else
		{
			m_modelHasUVs = true;
		}

		// Allocate memory for the arrays

		// C3DModel variables

		m_uvCoordsRaw = new float[m_numUVCoords * 2];
		m_UVindices = new unsigned short[m_numFaces * 3];

		// Zero-out indices arrays

		memset(m_UVindices, 0, sizeof(unsigned short) * m_numFaces * 3);
		memset(m_uvCoordsRaw, 0, sizeof(float) * m_numUVCoords * 2);

	
		if (readFileOk)
		{
			m_Initialized = true;

		/*if (!m_modelHasNormals)
			{
				computeFaceNormals();
			}*/
		}
	}

	else
	{
		cout << "Error ocurred while reading 3D model." << endl;
	}

	return readFileOk;


}



bool C3DModel_X::readXFile(const char * const filename)
{
	ifstream infile;
	string lineBuffer;
	bool readFileOk = true;
	int lineNumber = 0;
	string Token2;

	bool parsed = false;
	bool readingVertex = false;
	bool readingNormal = false;
	bool readingUV = false;
	bool readingFaceindx = false;
	bool readingTexture = false; //
	bool unrecognizedLine = false; //


	infile.open(filename);
	while (getline(infile, lineBuffer, '\n'))
	{
		istringstream strTK(lineBuffer);
		getline(strTK, Token2, ' ');
		if(Token2 == "Mesh")
		{
			readingVertex = true;
		
			getline(infile, lineBuffer, '\n');  lineNumber++;
			istringstream strTK(lineBuffer);
			getline(strTK, Token2, ';');
			m_numVertices = stoi(Token2);
			m_verticesRaw = new float[m_numVertices*3];
			memset(m_verticesRaw, 0, sizeof(float) * m_numVertices * 3);
				while (m_currentVertex != m_numVertices)
				{
				
					
					getline(infile, lineBuffer, '\n'); lineNumber++;
						istringstream strTK(lineBuffer);
						getline(strTK, Token2, ';');
						m_verticesRaw[(m_currentVertex * 3)] = stof(Token2);
						getline(strTK, Token2, ';');
						m_verticesRaw[(m_currentVertex * 3) + 1] = stof(Token2);
						getline(strTK, Token2, ';');
						m_verticesRaw[(m_currentVertex * 3) + 2] = stof(Token2);
					
					m_currentVertex++;
				}
				readingFaceindx = true;
				if (readingFaceindx)
				{
					getline(infile, lineBuffer, '\n'); lineNumber++;
					istringstream strTK(lineBuffer);
					getline(strTK, Token2, ';');

					m_numFaces = stoi(Token2);
					m_vertexIndices = new unsigned short[m_numFaces * 3];
					memset(m_vertexIndices, 0, sizeof(unsigned short) * m_numFaces * 3);
		
					while (m_currentFace != m_numFaces)
					{
						getline(infile, lineBuffer, '\n'); lineNumber++;
						istringstream strTK(lineBuffer);
						getline(strTK, Token2, ';');
						getline(strTK, Token2, ',');
						m_vertexIndices[(m_currentFace*3)] = (unsigned short)(stoi(Token2));
						getline(strTK, Token2, ',');
						m_vertexIndices[(m_currentFace*3) + 1] = (unsigned short)(stoi(Token2));
						getline(strTK, Token2, ',');
						m_vertexIndices[(m_currentFace * 3) + 2] = (unsigned short)(stoi(Token2));

							m_currentFace++;
					}
					readingFaceindx = false;
				}
				readingVertex = false;
			}
		if (Token2 == "MeshNormals")
		{
			readingNormal = true;
			getline(infile, lineBuffer, '\n');  lineNumber++;
			istringstream strTK(lineBuffer);
			getline(strTK, Token2, ';');
			m_numNormals= stoi(Token2);
			m_normalsRaw = new float[m_numNormals*3];
			memset(m_normalsRaw, 0, sizeof(float) * m_numNormals * 3);
		
		
			while (m_currentNormal != m_numNormals)
			{
				getline(infile, lineBuffer, '\n'); lineNumber++;
				istringstream strTK(lineBuffer);
				getline(strTK, Token2, ';');
				m_normalsRaw[(m_currentNormal * 3)] = stof(Token2);
				getline(strTK, Token2, ';');
				m_normalsRaw[(m_currentNormal * 3) + 1] = stof(Token2);
				getline(strTK, Token2, ';');
				m_normalsRaw[(m_currentNormal * 3) + 2] = stof(Token2);

				m_currentNormal++;
			}
			readingFaceindx = true;
			if (readingFaceindx)//   
			{
				getline(infile, lineBuffer, '\n'); lineNumber++;
				istringstream strTK(lineBuffer);
				getline(strTK, Token2, ';');

				m_numFaces = stoi(Token2); //
				m_normalIndices = new unsigned short[m_numFaces * 3]; //
				memset(m_normalIndices, 0, sizeof(unsigned short) * m_numFaces * 3); // necesary?
				m_currentFace = 0;
				while (m_currentFace != m_numFaces)
				{
					getline(infile, lineBuffer, '\n'); lineNumber++;
					istringstream strTK(lineBuffer);
					getline(strTK, Token2, ';');
					getline(strTK, Token2, ',');
					m_normalIndices[(m_currentFace * 3)] = (unsigned short)(stoi(Token2));
					getline(strTK, Token2, ',');
					m_normalIndices[(m_currentFace * 3) + 1] = (unsigned short)(stoi(Token2));
					getline(strTK, Token2, ',');
					m_normalIndices[(m_currentFace * 3) + 2] = (unsigned short)(stoi(Token2));

					m_currentFace++;
				}
				readingFaceindx = false;
			}
				readingNormal = false;
		}
		if(Token2 == "MeshTextureCoords")
		{
			readingUV = true;
			getline(infile, lineBuffer, '\n');  lineNumber++;
			istringstream strTK(lineBuffer);
			getline(strTK, Token2, ';');
			m_numUVCoords = stoi(Token2);
			// Allocate memory for the arrays
			// C3DModel variables
			m_uvCoordsRaw = new float[m_numUVCoords * 2];
			memset(m_uvCoordsRaw, 0, sizeof(float) * m_numUVCoords * 2);

			while (m_currentUV != m_numUVCoords)
			{
				getline(infile, lineBuffer, '\n'); lineNumber++;
				istringstream strTK(lineBuffer);
				getline(strTK, Token2, ';');
				m_uvCoordsRaw[(m_currentUV * 2)] = stof(Token2);
				getline(strTK, Token2, ';');
				m_uvCoordsRaw[(m_currentUV * 2)+1] = stof(Token2);
			
				m_currentUV++;
			}
			//m_UVindices = new unsigned short[m_numFaces * 3];
			//memset(m_UVindices, 0, sizeof(unsigned short) * m_numFaces * 3);

		}


	lineNumber++;
		}
	
	


	infile.close();

	return readFileOk;
}

