#pragma once
#include "Vector4.h"
#include "Vector3.h"

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

	void setPosition(Vector4 otherVectors);
	void setPosition(float x, float y, float z, float w);
	void setPosition(Vector3 otherVectors);
	void setPosition(float x, float y, float z);

	void setScale(Vector4 otherVector);
	void setScale(float x, float y, float z, float w);
	void setScale(Vector3 otherVector);
	void setScale(float x, float y, float z);

	Matrix4& transpose();

	//Matrix Maths
	Matrix4& operator* (const Matrix4 & otherMatrix);
	friend Matrix4& operator* (const Matrix4 & firstMatrix, const Matrix4 & secondMatrix);

	//Vector Maths
	Vector4& operator* (Vector4 & otherMatrix);
	friend Vector4& operator* (const Vector4 & otherVector, Matrix4 & otherMatrix);

	//Casts and Acccessors
	operator float*();
	float operator[] (int i);

	//Maths Ops
	void operator+=(const Vector4 & otherVector);
	void operator+=(const Vector3 & otherVector);

private:
	float matrixData[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} };
};

