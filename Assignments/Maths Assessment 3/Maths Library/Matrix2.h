#pragma once
#include <stdexcept>

class Matrix2
{
public:
	Matrix2();
	Matrix2(float, float, float, float);
	Matrix2(const Matrix2 & copy);

	~Matrix2();

	void setRotateX(float x);
	void setRotateZ(float z);
	void setValue(int index, float value);
	float getValue(int index);

	Matrix2& operator* (const Matrix2 & otherMatrix);
	friend Matrix2& operator* (const Matrix2 & firstMatrix, const Matrix2 & secondMatrix);
	float operator[] (int i);

	operator float*();

private:
	//[Column][Row]
	float matrixData[2][2] = { {1,0}, {0,1} };
};

