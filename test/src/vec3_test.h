#pragma once

#include "test.h"
#include "g3d/vec3.h"


using namespace g3d;

class Vec3Test : public test
{
public:
	void additionTest(const vec3& v1, const vec3& v2, const vec3& expectedResult)
	{
		addTestCase("Addition Test", [v1, v2, expectedResult]()
			{
				vec3 result = v1 + v2;

				std::cout << v1 << " + " << v2 << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Addition test failed!");
				}
			});
	}

	void subtractionTest(const vec3& v1, const vec3& v2, const vec3& expectedResult)
	{
		addTestCase("Subtraction Test", [v1, v2, expectedResult]()
			{
				vec3 result = v1 - v2;

				std::cout << v1 << " - " << v2 << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Subtraction test failed!");
				}
			});
	}

	void scalarMultiplicationTest(const vec3& v1, const int scalar, const vec3& expectedResult)
	{
		addTestCase("Scalar Multiplication Test", [v1, scalar, expectedResult]()
			{
				vec3 result = v1 * scalar;

				std::cout << v1 << " * " << scalar << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Scalar Multiplication test failed!");
				}
			});
	}

	void scalarDivisionTest(const vec3& v1, const int scalar, const vec3& expectedResult)
	{
		addTestCase("Scalar Division Test", [v1, scalar, expectedResult, this]()
			{
				vec3 result = v1 / scalar;

				std::cout << v1 << " / " << scalar << " = ";
				std::cout << result << "\n";

				if (!isAlmostEqual(result.x, expectedResult.x) && !isAlmostEqual(result.y, expectedResult.y)) {
					throw std::runtime_error("Scalar Division test failed!");
				}
			});
	}

	void equalityTest(const vec3& v1, const vec3& v2, const bool expectedResult)
	{
		addTestCase("Equality Test", [v1, v2, expectedResult]()
			{
				bool result = v1 == v2;

				std::cout << v1 << " == " << v2 << " = ";
				std::cout << (result ? "true" : "false") << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Equality test failed!");
				}
			});
	}

	void lessThanOrEqualTest(const vec3& v1, const vec3& v2, const bool expectedResult)
	{
		addTestCase("Less than or equal Test", [v1, v2, expectedResult]()
			{
				bool result = v1 <= v2;

				std::cout << v1 << " <= " << v2 << " = ";
				std::cout << (result ? "true" : "false") << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Less than or equal test failed!");
				}
			});
	}

	void greaterThanOrEqualTest(const vec3& v1, const vec3& v2, const bool expectedResult)
	{
		addTestCase("Greater than or equal Test", [v1, v2, expectedResult]()
			{
				bool result = v1 >= v2;

				std::cout << v1 << " >= " << v2 << " = ";
				std::cout << (result ? "true" : "false") << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Greater than or equal test failed!");
				}
			});
	}

	void normalizationTest(const vec3& v, const vec3& expectedResult)
	{
		addTestCase("Normalization Test", [v, expectedResult, this]()
			{
				vec3 normal = v.normalized();

				std::cout << "Original vector: " << v << "\n";
				std::cout << "Normalized vector: " << normal << "\n";

				if (!isAlmostEqual(normal.x, expectedResult.x) && !isAlmostEqual(normal.y, expectedResult.y)) {
					throw std::runtime_error("Normalization test failed!");
				}
			});
	}

	void magnitudeTest(const vec3& v, float expectedResult)
	{
		addTestCase("Magnitude Test", [v, expectedResult, this]()
			{
				float m = v.magnitude();

				std::cout << "Magnitude of " << v;
				std::cout << " = " << m << "\n";

				if (!isAlmostEqual(m, expectedResult)) {
					throw std::runtime_error("Normalization test failed!");
				}
			});
	}

	void dotProductTest(const vec3& v1, const vec3& v2, const float expectedResult)
	{
		addTestCase("Dot Product Test", [v1, v2, expectedResult]()
			{
				float result = vec3::dot(v1, v2);

				std::cout << v1 << " . " << v2 << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Dot Product test failed!");
				}
			});
	}

	void crossProductTest(const vec3& v1, const vec3& v2, const vec3& expectedResult)
	{
		addTestCase("Cross Product Test", [v1, v2, expectedResult]()
			{
				vec3 result = vec3::cross(v1, v2);

				std::cout << v1 << " x " << v2 << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y || result.z != expectedResult.z) {
					throw std::runtime_error("Cross Product test failed!");
				}
			});
	}
};