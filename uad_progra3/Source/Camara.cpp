#include "..\Include\CCamara.h"


CCamara::CCamara() :
	m_ActPos(0, 0, 0)
{
}


CCamara::~CCamara()
{
}

void CCamara::move(float deltaX, float deltaY)
{
	m_ActPos.setValues(m_ActPos.getX() + deltaX, m_ActPos.getY(), m_ActPos.getZ() - deltaY);
}

void CCamara::reset()
{

}

CVector3 CCamara::getPosition()
{
	return m_ActPos;
}