#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include <vector>
#include<iostream>

class Matrix3
{
public:
	Matrix3();
	Matrix3(float x, float y, float z, float w, float v, float u, float t, float s, float r);
	Matrix3(const Matrix3 & copy);
	Matrix3(const float* copy);

	~Matrix3();

	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);

	void setPosition(Vector3 otherVectors);
	void setPosition(float x, float y, float z);
	void setPosition(Vector2 otherVectors);
	void setPosition(float x, float y);

	void setScale(Vector3 otherVector);
	void setScale(float x, float y, float z);
	void setScale(Vector2 otherVector);
	void setScale(float x, float y);

	Matrix3& transpose();

	Matrix3 & operator*(const float * otherMatrix);

	//Matrix Maths
	Matrix3& operator* (const Matrix3 & otherMatrix);
	friend Matrix3& operator* (const Matrix3 & firstMatrix, const Matrix3 & secondMatrix);
	void operator*= (const Matrix3 & otherMatrix);
	Matrix3* multiply(const Matrix3 & otherMatrix);

	//Vector Maths
	Vector3& operator* (Vector3 & otherVector);
	friend Vector3& operator* (const Vector3 & otherVector, Matrix3 & otherMatrix);

	//Casts and Accessors
	operator float*();
	float operator[] (int i);

	//Maths Ops
	void operator+=(const Vector3 & otherVector);
	void operator+=(const Vector2 & otherVector);

	//Hierarchy
	void addParent(Matrix3* otherParent);
	void removeParent();
	void addChild(Matrix3* otherChild);
	void removeChild(Matrix3* otherChild);

	Matrix3 * getGlobal();

private:
	float matrixData[3][3] = { { 1,0,0 },{ 0,1,0 },{ 0,0,1 } };
	Matrix3* parent = nullptr;
	std::vector<Matrix3*> children;
};

