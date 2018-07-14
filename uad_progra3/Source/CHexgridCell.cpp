#include "..\Include\CHexgridCell.h"


CHexgridCell::CHexgridCell(float x, float z, const float sSize) //: graphicMemoryObjectID(nullptr)
{
	m_center.setValues(x,0,z);

	for (int i = 0; i < 5; i++) //angles are 0°, 60°, 120°, 180°, 240°, 300° and/or 360°
	{
		m_vertex[i].setValues(m_center.X + sSize * cos(angrad*(60*i)), 0, m_center.Y + sSize * sin(angrad*(60 * i)));
		cout << m_vertex[i].X << " " << m_vertex[i].Y << endl;
	}

}

CHexgridCell::~CHexgridCell()
{

}


CVector3 CHexgridCell::getCenter()
{
	return this->m_center;
}

/*
unsigned int * CHexgridCell::getGraphicMemoryObjectId()
{
	return graphicMemoryObjectID;
}*/

void CHexgridCell::getVertexes(float * pVertex)
{
	/*
	for (int f = 0; f < 5; f++)
	{
		pVertex[g] = m_vertex[f].getX();
		pVertex[g+1] = m_vertex[f].getY();
		pVertex[g+2] = m_vertex[f].getZ();
		
	}
	*/
	pVertex[0] = m_vertex[0].getX();
	pVertex[1] = m_vertex[0].getY();
	pVertex[2] = m_vertex[0].getZ();
	pVertex[3] = m_vertex[1].getX();
	pVertex[4] = m_vertex[1].getY();
	pVertex[5] = m_vertex[1].getZ();
	pVertex[6] = m_vertex[2].getX();
	pVertex[7] = m_vertex[2].getY();
	pVertex[8] = m_vertex[2].getZ();
	pVertex[9] = m_vertex[3].getX();
	pVertex[10] = m_vertex[3].getY();
	pVertex[11] = m_vertex[3].getZ();
	pVertex[12] = m_vertex[4].getX();
	pVertex[13] = m_vertex[4].getY();
	pVertex[14] = m_vertex[4].getZ();
	pVertex[15] = m_vertex[5].getX();
	pVertex[16] = m_vertex[5].getY();
	pVertex[17] = m_vertex[5].getZ();
}

CVector3 CHexgridCell::getPonits(int ponit)
{
	return m_vertex[ponit];
}