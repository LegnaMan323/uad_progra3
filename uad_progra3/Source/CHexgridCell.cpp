#include "..\Include\CHexgridCell.h"


CHexgridCell::CHexgridCell(float x, float z, const float sSize) //: graphicMemoryObjectID(nullptr)
{
	m_center.setValues(x,0,z);
	cout << "cX:" << m_center.X << "   cY:" << m_center.Z << endl;

	for (int i = 0; i < 6; i++) //angles are 0°, 60°, 120°, 180°, 240°, 300° and/or 360°
	{
		m_vertex[i].setValues(m_center.X + sSize * cos(angrad*(60*i)), 0, m_center.Z + sSize * sin(angrad*(60 * i)));
		cout << "X:" << m_vertex[i].X << "   Y:"  << m_vertex[i].Z << endl;
		cout << i << endl;
	}
}





CHexgridCell::~CHexgridCell()
{

}




CVector3 CHexgridCell::getCenter()
{
	return this->m_center;
}

