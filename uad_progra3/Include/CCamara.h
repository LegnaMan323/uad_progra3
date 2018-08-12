#pragma once


#include "CVector3.h"

class CCamara
{
private:
	CVector3 m_InitPos;
	CVector3 m_ActPos;
	CVector3 lookAt;
	CVector3 upVec;


public:
	CCamara();
	~CCamara();

	void move(float deltaX, float deltaY);
	void reset();
	CVector3 getPosition();
};

