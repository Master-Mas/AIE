#pragma once
#include <iostream>

struct MyStruct
{
public:
	MyStruct();
	MyStruct(int otherID);
	~MyStruct();

	void SetNext(MyStruct *other)
	{
		next = other;
	}

	void SetID(int id)
	{
		m_ID = id;
	}

	MyStruct * GetNext()
	{
		if (next != nullptr)
		{
			std::cout << "Error in MyStruct::GetNext()" << std::endl;
		}
		return next;
	}

	int GetID()
	{
		return m_ID;
	}



private:
	int m_ID;
	MyStruct *next = nullptr;

};

