#include "Matrix2.h"



Matrix2::Matrix2()
{
	matrixData = new float*[2];
	matrixData[0] = new float[2];
	matrixData[1] = new float[2];

	matrixData[0][0] = 1;
	matrixData[0][1] = 0;
	matrixData[1][0] = 0;
	matrixData[1][1] = 1;
}


// [ x, z ]
// [ y, a ]
Matrix2::Matrix2(float x, float y, float z, float a)
{
	matrixData = new float*[2];
	for (int i = 0; i < 2; i++)
	{
		matrixData[i] = new float[2];
	}

	matrixData[0][0] = x;
	matrixData[0][1] = y;
	matrixData[1][0] = z;
	matrixData[1][1] = a;
}

Matrix2::Matrix2(const Matrix2 & copy)
{
	matrixData = new float*[2];
	matrixData[0] = new float[2];
	matrixData[1] = new float[2];

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
	if (matrixData != nullptr)
	{
		for (int i = 0; i < 2; i++)
		{
			delete[] matrixData[i];
		}
		
		delete[] matrixData;

		matrixData = nullptr;
	}
}

void Matrix2::setRotateX(float x)
{
	matrixData[0][0] = cosf(x);
	matrixData[0][1] = sinf(x);
	matrixData[1][0] = asinf(x);
	matrixData[1][1] = cosf(x);
}

void Matrix2::setRotateZ(float z)
{
	matrixData[0][0] = cosf(z);
	matrixData[0][1] = sinf(z);
	matrixData[1][0] = asinf(z);
	matrixData[1][1] = cosf(z);
}

void Matrix2::setValue(int index, float value)
{
	if (index > 0 && index < 4)
	{
		matrixData[index / 2][index % 2] = value;
	}
	else
	{
		throw std::out_of_range("Matrix2 setValue outside of range");
	}
}

float Matrix2::getValue(int index)
{
	if (index > 0 && index < 4)
	{
		return matrixData[index / 2][index % 2];
	}
	else
	{
		throw std::out_of_range("Matrix2 setValue outside of range");
	}
}

Matrix2& Matrix2::operator*(const Matrix2 & otherMatrix)
{
	Matrix2* temp = new Matrix2();

	for (int i = 0; i < 2; ++i)
	{
		for (int ii = 0; ii < 2; ++ii)
		{
			for (int iii = 0; iii < 2; ++iii)
			{
				temp->matrixData[i][ii] += matrixData[i][iii] * otherMatrix.matrixData[iii][ii];
			}
		}
	}

	return *temp;
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
