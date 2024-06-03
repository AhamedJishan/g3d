#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>


class test
{
public:
	virtual ~test() = default;

	void addTestCase(const char* name,std::function<void()> func)
	{
		testCases.push_back({ name, func });
	}

	void run()
	{
		unsigned int passed = 0;
		unsigned int failed = 0;

		for (const auto& test : testCases)
		{
			std::cout << "Running Test: " << test.name << "\n";
			try
			{
				test.testFunction();
				std::cout << "Test Passed: " << test.name << "\n\n";
				passed++;
			}
			catch (const std::exception& e)
			{
				std::cout << "Test Failed: " << test.name << "\n";
				std::cout << "Reason: " << e.what() << "\n\n";
				failed++;
			}
		}

		std::cout << "\n-----------------------------------------------------\n";
		std::cout << "Test Summary: " << passed << " passed, " << failed << " failed.\n";
		std::cout << "-----------------------------------------------------\n";
	}

protected:
	struct TestCase
	{
		const char* name;
		std::function<void()> testFunction;
	};

	std::vector<TestCase> testCases;

	bool isAlmostEqual(float a, float b, float tolerance = 0.00001f)
	{
		if (std::abs(a - b) >= tolerance)
		{
			std::cout << "Assertion failed: values are not approximately equal!\n";
			return false;
		}
		return true;
	}
};