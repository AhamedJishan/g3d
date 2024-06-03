#pragma once

#include "test.h"
#include "g3d/vec2.h"


using namespace g3d;

class VectorTest : public test
{
public:
	void additionTest(const vec2& v1, const vec2& v2, const vec2& expectedResult)
	{
		addTestCase("Addition Test", [v1, v2, expectedResult]()
			{
                vec2 result = v1 + v2;

                std::cout << v1 << " + " << v2 << " = ";
                std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Addition test failed!");
				}
			});
	}

	void subtractionTest(const vec2& v1, const vec2& v2, const vec2& expectedResult)
	{
		addTestCase("Subtraction Test", [v1, v2, expectedResult]()
			{
				vec2 result = v1 - v2;

				std::cout << v1 << " - " << v2 << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Subtraction test failed!");
				}
			});
	}

	void scalarMultiplicationTest(const vec2& v1, const int scalar, const vec2& expectedResult)
	{
		addTestCase("Scalar Multiplication Test", [v1, scalar, expectedResult]()
			{
				vec2 result = v1 * scalar;

				std::cout << v1 << " * " << scalar << " = ";
				std::cout << result << "\n";

				if (result.x != expectedResult.x || result.y != expectedResult.y) {
					throw std::runtime_error("Scalar Multiplication test failed!");
				}
			});
	}

	void scalarDivisionTest(const vec2& v1, const int scalar, const vec2& expectedResult)
	{
		addTestCase("Scalar Division Test", [v1, scalar, expectedResult, this]()
			{
				vec2 result = v1 / scalar;

				std::cout << v1 << " / " << scalar << " = ";
				std::cout << result << "\n";

				if (!isAlmostEqual(result.x, expectedResult.x) && !isAlmostEqual(result.y, expectedResult.y)) {
					throw std::runtime_error("Scalar Division test failed!");
				}
			});
	}

	void normalizationTest(const vec2& v, const vec2& expectedResult)
	{
		addTestCase("Normalization Test", [v, expectedResult, this]()
			{
				vec2 normal = v.normalized();

				std::cout << "Original vector: " << v << "\n";
				std::cout << "Normalized vector: " << normal << "\n";

				if (!isAlmostEqual(normal.x, expectedResult.x) && !isAlmostEqual(normal.y, expectedResult.y)) {
					throw std::runtime_error("Normalization test failed!");
				}
			});
	}

	void magnitudeTest(const vec2& v, float expectedResult)
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

	void dotProductTest(const vec2& v1, const vec2& v2, const float expectedResult)
	{
		addTestCase("Dot Product Test", [v1, v2, expectedResult]()
			{
				float result = vec2::dot(v1, v2);

				std::cout << v1 << " . " << v2 << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Dot Product test failed!");
				}
			});
	}

	void crossProductTest(const vec2& v1, const vec2& v2, const float expectedResult)
	{
		addTestCase("Dot Product Test", [v1, v2, expectedResult]()
			{
				float result = vec2::cross(v1, v2);

				std::cout << v1 << " x " << v2 << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Dot Product test failed!");
				}
			});
	}
};