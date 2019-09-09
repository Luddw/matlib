#include "matlib.h"
#include <iostream>

int main() 
{
	Matrix4D h(1, 1, 1, -1, 
				1, 1, -1, 1, 
				1, -1, 1, 1,
				-1, 1, 1, 1);
	Matrix4D l;

	l = Matrix4D::Inverse(h);
	l = l * h;
	l = l * h;
}