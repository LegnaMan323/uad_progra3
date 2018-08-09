#pragma once

#ifndef CQUADTREE
#define CQUADTREE


#include "../Include/CVector3.h"
#include <iostream>
using namespace std;




class CQuadTree
{
private:


	int subDivideLimit;



public:

	CQuadTree();
	~CQuadTree();

	void BuildQuadTree();
	void Render();


};

#endif //!CQUADTREE