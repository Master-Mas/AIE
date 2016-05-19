#pragma once

#include <stdexcept>
#include <iostream>

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

	Matrix4& operator* (const Matrix4 & otherMatrix);
	friend Matrix4& operator* (const Matrix4 & firstMatrix, const Matrix4 & secondMatrix);
	float operator[] (int i);

	operator float*();

private:
	float matrixData[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} };
};

