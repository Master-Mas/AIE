#pragma once

#include <stdexcept>

class Matrix3
{
public:
	Matrix3();
	Matrix3(float x, float y, float z, float w, float v, float u, float t, float s, float r);
	Matrix3(const Matrix3 & copy);

	~Matrix3();

	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	void setValue(int index, float value);
	float getValue(int index);

	Matrix3& operator* (const Matrix3 & otherMatrix);
	friend Matrix3& operator* (const Matrix3 & firstMatrix, const Matrix3 & secondMatrix);
	float operator[] (int i);

	operator float*();

private:
	//[Column][Row]
	float** matrixData;
};

