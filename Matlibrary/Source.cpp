#include "matlib.h"
#include <iostream>

int main() 
{
	Matrix4D h(1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1);
	std::cout << h.Det();
}