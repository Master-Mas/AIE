#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float, float, float, float);
	Matrix2(const Matrix2 & copy);

	~Matrix2();

	void setRotateX(float x);
	void setRotateZ(float z);

	void setPosition(Vector2 otherVectors);
	void setPosition(float x, float y);

	void setScale(Vector2 otherVector);
	void setScale(float x, float y);

	Matrix2& transpose();

	//Matrix Maths
	Matrix2& operator* (const Matrix2 & otherMatrix);
	friend Matrix2& operator* (const Matrix2 & firstMatrix, const Matrix2 & secondMatrix);

	//Vector Maths
	Vector2& operator* (Vector2 & otherVector);
	friend Vector2& operator* (const Vector2 & otherVector, Matrix2 & otherMatrix);

	//Casts and Accessors
	float operator[] (int i);
	operator float*();

	//Maths Ops
	void operator+=(const Vector2 & otherVector);

private:
	float matrixData[2][2] = { {1,0}, {0,1} };
};

