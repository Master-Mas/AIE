#include "Matrix3.h"



Matrix3::Matrix3()
{

}

Matrix3::Matrix3(float x, float y, float z, float w, float v, float u, float t, float s, float r)
{

	matrixData[0][0] = x;
	matrixData[0][1] = y;
	matrixData[0][2] = z;
	
	matrixData[1][0] = w;
	matrixData[1][1] = v;
	matrixData[1][2] = u;

	matrixData[2][0] = t;
	matrixData[2][1] = s;
	matrixData[2][2] = r;
}

Matrix3::Matrix3(const Matrix3 & copy)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int ii = 0; ii < 3; ++ii)
		{
			matrixData[i][ii] = copy.matrixData[i][ii];
		}
	}
}


Matrix3::~Matrix3()
{
}

void Matrix3::setRotateX(float x)
{
	matrixData[1][1] = cosf(x);
	matrixData[2][1] = -sinf(x);
	matrixData[1][2] = sinf(x);
	matrixData[2][2] = cosf(x);
}

void Matrix3::setRotateY(float y)
{
	matrixData[0][0] = cosf(y);
	matrixData[0][2] = -sinf(y);
	matrixData[2][0] = sinf(y);
	matrixData[2][2] = cosf(y);
}

void Matrix3::setRotateZ(float z)
{
	matrixData[0][0] = cosf(z);
	matrixData[1][0] = -sinf(z);
	matrixData[0][1] = sinf(z);
	matrixData[1][1] = cosf(z);
}

void Matrix3::setValue(int index, float value)
{
	if (index > 0 && index < 9)
	{
		matrixData[index / 3][index % 3] = value;
	}
	else
	{
		throw std::out_of_range("Matrix3 setValue outside of range");
	}
}

float Matrix3::getValue(int index)
{
	if (index > 0 && index < 9)
	{
		return matrixData[index / 3][index % 3];
	}
	else
	{
		throw std::out_of_range("Matrix3 setValue outside of range");
	}
}

Matrix3& Matrix3::operator*(const Matrix3 & otherMatrix)
{
	Matrix3 temp = Matrix3();

	temp.matrixData[0][0] = (matrixData[0][0] * otherMatrix.matrixData[0][0]) + (matrixData[1][0] * otherMatrix.matrixData[0][1]) + (matrixData[2][0] * otherMatrix.matrixData[0][2]);
	temp.matrixData[0][1] = (matrixData[0][1] * otherMatrix.matrixData[0][0]) + (matrixData[1][1] * otherMatrix.matrixData[0][1]) + (matrixData[2][1] * otherMatrix.matrixData[0][2]);
	temp.matrixData[0][2] = (matrixData[0][2] * otherMatrix.matrixData[0][0]) + (matrixData[1][2] * otherMatrix.matrixData[0][1]) + (matrixData[2][2] * otherMatrix.matrixData[0][2]);

	temp.matrixData[1][0] = (matrixData[0][0] * otherMatrix.matrixData[1][0]) + (matrixData[1][0] * otherMatrix.matrixData[1][1]) + (matrixData[2][0] * otherMatrix.matrixData[1][2]);
	temp.matrixData[1][1] = (matrixData[0][1] * otherMatrix.matrixData[1][0]) + (matrixData[1][1] * otherMatrix.matrixData[1][1]) + (matrixData[2][1] * otherMatrix.matrixData[1][2]);
	temp.matrixData[1][2] = (matrixData[0][2] * otherMatrix.matrixData[1][0]) + (matrixData[1][2] * otherMatrix.matrixData[1][1]) + (matrixData[2][2] * otherMatrix.matrixData[1][2]);

	temp.matrixData[2][0] = (matrixData[0][0] * otherMatrix.matrixData[2][0]) + (matrixData[1][0] * otherMatrix.matrixData[2][1]) + (matrixData[2][0] * otherMatrix.matrixData[2][2]);
	temp.matrixData[2][1] = (matrixData[0][1] * otherMatrix.matrixData[2][0]) + (matrixData[1][1] * otherMatrix.matrixData[2][1]) + (matrixData[2][1] * otherMatrix.matrixData[2][2]);
	temp.matrixData[2][2] = (matrixData[0][2] * otherMatrix.matrixData[2][0]) + (matrixData[1][2] * otherMatrix.matrixData[2][1]) + (matrixData[2][2] * otherMatrix.matrixData[2][2]);

	return temp;
}

float Matrix3::operator[](int i)
{
	if (i > sizeof(matrixData) || i < 0)
	{
		return *(matrixData[i]);
	}
	else
	{
		throw std::out_of_range("Index is not in range of Matrix3");
	}
}

Matrix3::operator float*()
{
	float allData[9] = 
	{ 
		matrixData[0][0], matrixData[0][1], matrixData[0][2], 
		matrixData[1][0], matrixData[1][1], matrixData[1][2],
		matrixData[2][0], matrixData[2][1], matrixData[2][2]
	};

	return allData;
}

Matrix3& operator*(const Matrix3 & firstMatrix, const Matrix3 & secondMatrix)
{
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; ++i)
	{
		for (int ii = 0; ii < 3; ++ii)
		{
			for (int iii = 0; iii < 3; ++iii)
			{
				temp.matrixData[i][ii] += firstMatrix.matrixData[i][iii] * secondMatrix.matrixData[iii][ii];
			}
		}
	}

	return temp;
}
