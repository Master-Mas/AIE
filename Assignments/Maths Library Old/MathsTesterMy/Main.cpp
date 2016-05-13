#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
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

template <typename T>
void TEST(const char* msg, T& a, T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
	}
}

void main()
{
	Vector4 v1, v2;

	v1 = Vector4(13.5f, -48.23f, 862, 0);
	v2 = Vector4(5, 3.99f, -12, 1);

	TEST("Vector4 cross", v1.cross(v2), Vector4(-2860.62011719f, 295.014984131f, 295.014984131f, 0));

	//std::cout << v3.toString() << "\n";

	system("pause");
}