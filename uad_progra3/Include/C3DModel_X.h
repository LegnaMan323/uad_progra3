#pragma once

#ifndef C3DMODEL_X_H
#define C3DMODEL_X_H

#include "C3DModel.h"
#include <string>
using namespace std;

class C3DModel_X : public C3DModel
{
private:
	int m_currentVertex, m_currentNormal, m_currentFace, m_currentUV;
	bool readXFile(const char * const filename);		// Read object from file 
protected: 
	void reset();														// Cleanup any allocated memory
	bool loadFromFile(const char * const filename);
public:
	C3DModel_X();
	~C3DModel_X();

};



#endif //C3DMODEL_X_H 
