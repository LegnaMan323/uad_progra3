#pragma once

#ifdef XLOADER 
#define XLOADER_DLL extern "C" __declspec(dllexport)

#else 
#define XLOADER_DLL extern "C" __declspec(dllimport)

#endif

#include "C3DModel.h"
using namespace std;


XLOADER_DLL class C3DModel_X : public C3DModel
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