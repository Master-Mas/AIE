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

Matrix3::Matrix3(const float * copy)
{
	matrixData[0][0] = copy[0];
	matrixData[0][1] = copy[1];
	matrixData[0][2] = copy[2];

	matrixData[1][0] = copy[3];
	matrixData[1][1] = copy[4];
	matrixData[1][2] = copy[5];

	matrixData[2][0] = copy[6];
	matrixData[2][1] = copy[7];
	matrixData[2][2] = copy[8];
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

void Matrix3::setPosition(Vector3 otherVector)
{
	matrixData[2][0] = otherVector.x;
	matrixData[2][1] = otherVector.y;
	matrixData[2][2] = otherVector.z;
}

void Matrix3::setPosition(float x, float y, float z)
{
	matrixData[2][0] = x;
	matrixData[2][1] = y;
	matrixData[2][2] = z;
}

void Matrix3::setPosition(Vector2 otherVector)
{
	matrixData[2][0] = otherVector.x;
	matrixData[2][1] = otherVector.y;
}

void Matrix3::setPosition(float x, float y)
{
	matrixData[2][0] = x;
	matrixData[2][1] = y;
}

void Matrix3::setScale(Vector3 otherVector)
{
	matrixData[0][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
	matrixData[2][2] = otherVector.z;
}

void Matrix3::setScale(float x, float y, float z)
{
	matrixData[0][0] = x;
	matrixData[1][1] = y;
	matrixData[2][2] = z;
}

void Matrix3::setScale(Vector2 otherVector)
{
	matrixData[0][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
}

void Matrix3::setScale(float x, float y)
{
	matrixData[0][0] = x;
	matrixData[1][1] = y;
}

Matrix3 & Matrix3::transpose()
{
	Matrix3* temp = new Matrix3();

	temp->matrixData[0][0] = matrixData[0][0];
	temp->matrixData[0][1] = matrixData[1][0];
	temp->matrixData[0][2] = matrixData[2][0];

	temp->matrixData[1][0] = matrixData[0][1];
	temp->matrixData[1][1] = matrixData[1][1];
	temp->matrixData[1][2] = matrixData[2][1];

	temp->matrixData[2][0] = matrixData[0][2];
	temp->matrixData[2][1] = matrixData[1][2];
	temp->matrixData[2][2] = matrixData[2][2];

	return *temp;
}

Matrix3& Matrix3::operator*(const float* otherMatrix)
{
	Matrix3 temp = Matrix3();

	temp.matrixData[0][0] = (matrixData[0][0] * otherMatrix[0]) + (matrixData[1][0] * otherMatrix[1]) + (matrixData[2][0] * otherMatrix[2]);
	temp.matrixData[0][1] = (matrixData[0][1] * otherMatrix[0]) + (matrixData[1][1] * otherMatrix[1]) + (matrixData[2][1] * otherMatrix[2]);
	temp.matrixData[0][2] = (matrixData[0][2] * otherMatrix[0]) + (matrixData[1][2] * otherMatrix[1]) + (matrixData[2][2] * otherMatrix[2]);

	temp.matrixData[1][0] = (matrixData[0][0] * otherMatrix[3]) + (matrixData[1][0] * otherMatrix[4]) + (matrixData[2][0] * otherMatrix[5]);
	temp.matrixData[1][1] = (matrixData[0][1] * otherMatrix[3]) + (matrixData[1][1] * otherMatrix[4]) + (matrixData[2][1] * otherMatrix[5]);
	temp.matrixData[1][2] = (matrixData[0][2] * otherMatrix[3]) + (matrixData[1][2] * otherMatrix[4]) + (matrixData[2][2] * otherMatrix[5]);

	temp.matrixData[2][0] = (matrixData[0][0] * otherMatrix[6]) + (matrixData[1][0] * otherMatrix[7]) + (matrixData[2][0] * otherMatrix[8]);
	temp.matrixData[2][1] = (matrixData[0][1] * otherMatrix[6]) + (matrixData[1][1] * otherMatrix[7]) + (matrixData[2][1] * otherMatrix[8]);
	temp.matrixData[2][2] = (matrixData[0][2] * otherMatrix[6]) + (matrixData[1][2] * otherMatrix[7]) + (matrixData[2][2] * otherMatrix[8]);

	return temp;
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

void Matrix3::operator*=(const Matrix3 & otherMatrix)
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

	matrixData[0][0] = temp.matrixData[0][0];
	matrixData[0][1] = temp.matrixData[0][1];
	matrixData[0][2] = temp.matrixData[0][2];

	matrixData[1][0] = temp.matrixData[1][0];
	matrixData[1][1] = temp.matrixData[1][1];
	matrixData[1][2] = temp.matrixData[1][2];

	matrixData[2][0] = temp.matrixData[2][0];
	matrixData[2][1] = temp.matrixData[2][1];
	matrixData[2][2] = temp.matrixData[2][2];
}

Matrix3 * Matrix3::multiply(const Matrix3 & otherMatrix)
{
	Matrix3* temp = new Matrix3();

	temp->matrixData[0][0] = (matrixData[0][0] * otherMatrix.matrixData[0][0]) + (matrixData[1][0] * otherMatrix.matrixData[0][1]) + (matrixData[2][0] * otherMatrix.matrixData[0][2]);
	temp->matrixData[0][1] = (matrixData[0][1] * otherMatrix.matrixData[0][0]) + (matrixData[1][1] * otherMatrix.matrixData[0][1]) + (matrixData[2][1] * otherMatrix.matrixData[0][2]);
	temp->matrixData[0][2] = (matrixData[0][2] * otherMatrix.matrixData[0][0]) + (matrixData[1][2] * otherMatrix.matrixData[0][1]) + (matrixData[2][2] * otherMatrix.matrixData[0][2]);

	temp->matrixData[1][0] = (matrixData[0][0] * otherMatrix.matrixData[1][0]) + (matrixData[1][0] * otherMatrix.matrixData[1][1]) + (matrixData[2][0] * otherMatrix.matrixData[1][2]);
	temp->matrixData[1][1] = (matrixData[0][1] * otherMatrix.matrixData[1][0]) + (matrixData[1][1] * otherMatrix.matrixData[1][1]) + (matrixData[2][1] * otherMatrix.matrixData[1][2]);
	temp->matrixData[1][2] = (matrixData[0][2] * otherMatrix.matrixData[1][0]) + (matrixData[1][2] * otherMatrix.matrixData[1][1]) + (matrixData[2][2] * otherMatrix.matrixData[1][2]);

	temp->matrixData[2][0] = (matrixData[0][0] * otherMatrix.matrixData[2][0]) + (matrixData[1][0] * otherMatrix.matrixData[2][1]) + (matrixData[2][0] * otherMatrix.matrixData[2][2]);
	temp->matrixData[2][1] = (matrixData[0][1] * otherMatrix.matrixData[2][0]) + (matrixData[1][1] * otherMatrix.matrixData[2][1]) + (matrixData[2][1] * otherMatrix.matrixData[2][2]);
	temp->matrixData[2][2] = (matrixData[0][2] * otherMatrix.matrixData[2][0]) + (matrixData[1][2] * otherMatrix.matrixData[2][1]) + (matrixData[2][2] * otherMatrix.matrixData[2][2]);

	return temp;
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

Vector3 & Matrix3::operator*(Vector3 & otherVector)
{
	float* matrix = (float*)*this;

	return Vector3(
		matrix[0] * otherVector.x + matrix[3] * otherVector.y + matrix[6] * otherVector.z,
		matrix[1] * otherVector.x + matrix[4] * otherVector.y + matrix[7] * otherVector.z,
		matrix[2] * otherVector.x + matrix[5] * otherVector.y + matrix[8] * otherVector.z);
}

Vector3 & operator*(const Vector3 & otherVector, Matrix3 & otherMatrix)
{
	float* matrix = (float*)otherMatrix;

	return Vector3(
		matrix[0] * otherVector.x + matrix[3] * otherVector.y + matrix[6] * otherVector.z,
		matrix[1] * otherVector.x + matrix[4] * otherVector.y + matrix[7] * otherVector.z,
		matrix[2] * otherVector.x + matrix[5] * otherVector.y + matrix[8] * otherVector.z);
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

void Matrix3::operator+=(const Vector3 & otherVector)
{
	matrixData[2][0] += otherVector.x;
	matrixData[2][1] += otherVector.y;
	matrixData[2][2] += otherVector.z;
}

void Matrix3::operator+=(const Vector2 & otherVector)
{
	matrixData[2][0] += otherVector.x;
	matrixData[2][1] += otherVector.y;
}

void Matrix3::addParent(Matrix3 * otherParent)
{
	std::cout << "Add Parent" << std::endl;
	parent = otherParent;
	otherParent->children.push_back(this);
}

void Matrix3::removeParent()
{
	parent = nullptr;
}

void Matrix3::addChild(Matrix3 * otherChild)
{
	children.push_back(otherChild);
	otherChild->parent = this;
}

void Matrix3::removeChild(Matrix3 * otherChild)
{
	for (int i = 0; i < children.size(); i++)
	{
		Matrix3* testing = children.at(i);
		float* testingData = (float*)testing;

		float* otherData = (float*)otherChild;

		for (int ii = 0; ii < 9; ii++) {
			if (testingData[ii] != otherData[ii]) {
				break;
			}

			if (ii == 8)
			{
				children.erase(children.begin() + ii, children.begin() + ii);
				return;
			}
		}
	}
}

Matrix3 * Matrix3::getGlobal()
{
	if (parent != nullptr)
	{
		Matrix3 parentTemp = *parent->getGlobal();
		Matrix3* temp = parentTemp.multiply(*this);

		return temp;
	}
	else
	{
		return this;
	}
}
