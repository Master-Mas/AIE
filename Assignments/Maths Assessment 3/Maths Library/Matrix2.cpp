#include "Matrix2.h"

Matrix2::Matrix2()
{
}

Matrix2::Matrix2(float x, float y, float z, float a)
{
	matrixData[0][0] = x;
	matrixData[0][1] = y;
	matrixData[1][0] = z;
	matrixData[1][1] = a;
}

Matrix2::Matrix2(const Matrix2 & copy)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int ii = 0; ii < 2; ++ii)
		{
			matrixData[i][ii] = copy.matrixData[i][ii];
		}
	}
}


Matrix2::~Matrix2()
{
	
}

void Matrix2::setRotateX(float x)
{
	matrixData[0][0] = cosf(x);
	matrixData[0][1] = sinf(x);
	matrixData[1][0] = -sinf(x);
	matrixData[1][1] = cosf(x);
}

void Matrix2::setRotateZ(float z)
{
	matrixData[0][0] = cosf(z);
	matrixData[0][1] = sinf(z);
	matrixData[1][0] = -sinf(z);
	matrixData[1][1] = cosf(z);
}

void Matrix2::setPosition(Vector2 otherVector)
{
	matrixData[1][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
}

void Matrix2::setPosition(float x, float y)
{
	matrixData[1][0] = x;
	matrixData[1][1] = y;
}

void Matrix2::setScale(Vector2 otherVector)
{
	matrixData[0][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
}

void Matrix2::setScale(float x, float y)
{
	matrixData[0][0] = x;
	matrixData[1][1] = y;
}

Matrix2 & Matrix2::transpose()
{
	Matrix2 temp = Matrix2();

	temp.matrixData[0][0] = matrixData[0][0];
	temp.matrixData[0][1] = matrixData[1][0];
	temp.matrixData[1][0] = matrixData[0][1];
	temp.matrixData[1][1] = matrixData[1][1];

	return temp;
}

Matrix2& Matrix2::operator*(const Matrix2 & otherMatrix)
{
	Matrix2* temp = new Matrix2();

	temp->matrixData[0][0] = (matrixData[0][0] * otherMatrix.matrixData[0][0]) + (matrixData[1][0] * otherMatrix.matrixData[0][1]);
	temp->matrixData[1][0] = (matrixData[0][0] * otherMatrix.matrixData[1][0]) + (matrixData[1][0] * otherMatrix.matrixData[1][1]);
	temp->matrixData[0][1] = (matrixData[0][1] * otherMatrix.matrixData[0][0]) + (matrixData[1][1] * otherMatrix.matrixData[0][1]);
	temp->matrixData[1][1] = (matrixData[0][1] * otherMatrix.matrixData[1][0]) + (matrixData[1][1] * otherMatrix.matrixData[1][1]);

	return *temp;
}

Matrix2& operator*(const Matrix2 & firstMatrix, const Matrix2 & secondMatrix)
{
	Matrix2 temp = Matrix2();

	for (int i = 0; i < 2; ++i)
	{
		for (int ii = 0; ii < 2; ++ii)
		{
			for (int iii = 0; iii < 2; ++iii)
			{
				temp.matrixData[i][ii] += firstMatrix.matrixData[i][iii] * secondMatrix.matrixData[iii][ii];
			}
		}
	}

	return temp;
}

Vector2& Matrix2::operator*(Vector2 & otherVector)
{
	float* matrix = (float*)*this;

	return Vector2(
		matrix[0] * otherVector.x + matrix[2] * otherVector.y,
		matrix[1] * otherVector.x + matrix[3] * otherVector.y);
}

Vector2 & operator*(const Vector2 & otherVector, Matrix2 & otherMatrix)
{
	float* matrix = (float*)otherMatrix;

	return Vector2(
		(matrix[0] * otherVector.x) + (matrix[2] * otherVector.y),
		(matrix[1] * otherVector.x) + (matrix[3] * otherVector.y));
}

float Matrix2::operator[](int i)
{
	if (i > sizeof(matrixData) || i < 0)
	{
		return *(matrixData[i]);
	}
	else
	{
		throw std::out_of_range("Index is not in range of Matrix2");
	}
}

Matrix2::operator float*()
{
	float allData[4] = { matrixData[0][0] , matrixData[0][1], matrixData[1][0], matrixData[1][1] };

	return allData;
}

void Matrix2::operator+=(const Vector2 & otherVector)
{
	matrixData[1][0] += otherVector.x;
	matrixData[1][1] += otherVector.y;
}