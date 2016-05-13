#include "MyStruct.h"
#include <iostream>


MyStruct::MyStruct()
{
}

MyStruct::MyStruct(int otherID)
{
	std::cout << "Calling second constructor for MyStruct." << std::endl;
	next = nullptr;
	m_ID = otherID;
}


MyStruct::~MyStruct()
{
}
