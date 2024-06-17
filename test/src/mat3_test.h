#pragma once

#include "g3d/g3d.h"
#include "test.h"

using namespace g3d;

class Mat3Test : public test
{
public:
	void matrixAdditionTest(const mat3& m1, const mat3& m2, const mat3& expectedResult)
	{
		addTestCase("Matrix Addition Test", [m1, m2, expectedResult]()
			{
				mat3 result = m1 + m2;

				std::cout << m1 << " + " << m2 << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Matrix Sum test failed!");
				}
			});
	}

	void matrixSubtractionTest(const mat3& m1, const mat3& m2, const mat3& expectedResult)
	{
		addTestCase("Matrix Subtraction Test", [m1, m2, expectedResult]()
			{
				mat3 result = m1 - m2;

				std::cout << m1 << " - " << m2 << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Matrix Subtraction test failed!");
				}
			});
	}

	void matrixProductTest(const mat3& m1, const mat3& m2, const mat3& expectedResult)
	{
		addTestCase("Matrix Product Test", [m1, m2, expectedResult]()
			{
				mat3 result = m1 * m2;

				std::cout << m1 << " x " << m2 << " = ";
				std::cout << result << "\n";
				
				if (result != expectedResult) {
					throw std::runtime_error("Matrix Product test failed!");
				}
			});
	}

	void scalarProductTest(const mat3& m, float s, const mat3& expectedResult)
	{
		addTestCase("Scalar Matrix Product Test", [m, s, expectedResult]()
			{
				mat3 result = m * s;

				std::cout << m << " x " << s << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Scalar Matrix Product test failed!");
				}
			});
	}

	void scalarDivisionTest(const mat3& m, float s, const mat3& expectedResult)
	{
		addTestCase("Scalar Matrix Division Test", [m, s, expectedResult]()
			{
				mat3 result = m / s;

				std::cout << m << " / " << s << " = ";
				std::cout << result << "\n";

				if (result != expectedResult) {
					throw std::runtime_error("Scalar Matrix Division test failed!");
				}
			});
	}
};