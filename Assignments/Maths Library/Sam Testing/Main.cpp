#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix2.h"
#include "Main.h"

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compare(Vector2& A, Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	float* a = (float*)A;
	float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance ||
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compare(Vector4& A, Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
	float* a = (float*)A;
	float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance ||
		abs(a[1] - b[1]) > tolerance ||
		abs(a[2] - b[2]) > tolerance ||
		abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compare(Vector3& A, Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	float* a = (float*)A;
	float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance ||
		abs(a[1] - b[1]) > tolerance ||
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

bool compare(Matrix2& A, Matrix2& B, float tolerance = DEFAULT_TOLERANCE) {
	float* a = (float*)A;
	float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance ||
		abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

template <typename T>
void TEST(const char* msg, T& a, T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
	}
}

void main()
{

	Matrix2 m2;
	m2.setRotateZ(4.576f);

	Matrix2 m2b, m2c;
	m2b.setRotateZ(-2.145f);
	m2c = m2 * m2b;

	TEST("Matrix2 rotate", m2, Matrix2(-0.135966f, -0.990713f, 0.990713f, -0.135966f));
	TEST("Matrix2 multiply", m2c, Matrix2(-0.757975637913f, 0.652282953262f, -0.652282953262f, -0.757975637913f));

	system("pause");
}