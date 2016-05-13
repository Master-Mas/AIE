#pragma once

#include <stdexcept>

class Matrix4
{
public:
	Matrix4();
	Matrix4(float x, float y, float z, float w, float v, float u, float t, float s, float r, float q, float p, float o, float n, float m, float l, float k);
	Matrix4(const Matrix4 & copy);

	~Matrix4();

	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	void setValue(int index, float value);
	float getValue(int index);

	Matrix4& operator* (const Matrix4 & otherMatrix);
	friend Matrix4& operator* (const Matrix4 & firstMatrix, const Matrix4 & secondMatrix);
	float operator[] (int i);

	operator float*();

private:
	//[Column][Row]
	float** matrixData;
};

