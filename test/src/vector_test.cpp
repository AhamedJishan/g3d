#include "g3d/vector.h"
#include <iostream>
#include <cassert>

int main() {
    // Test case for vec2 constructor
    {
        std::cout << "Test case: vec2 constructor\n";

        // Arrange
        float x = 3.0f, y = 4.0f;

        // Act
        g3d::vec2 v(x, y);

        // Assert
        std::cout << "Vector created: (" << v.x << ", " << v.y << ")\n";
        assert(v.x == x && v.y == y);
        std::cout << "Test result: Passed\n";
    }

    // Test case for addition operator
    {
        std::cout << "\nTest case: Addition operator\n";

        // Arrange
        g3d::vec2 v1(1.0f, 2.0f);
        g3d::vec2 v2(3.0f, 4.0f);

        // Act
        g3d::vec2 result = v1 + v2;

        // Assert
        std::cout << "(" << v1.x << ", " << v1.y << ") + (" << v2.x << ", " << v2.y << ") = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";
        assert(result.x == 4.0f && result.y == 6.0f);
        std::cout << "Test result: Passed\n";
    }

    // Test case for subtraction operator
    {
        std::cout << "\nTest case: Subtraction operator\n";

        // Arrange
        g3d::vec2 v1(5.0f, 8.0f);
        g3d::vec2 v2(2.0f, 3.0f);

        // Act
        g3d::vec2 result = v1 - v2;

        // Assert
        std::cout << "(" << v1.x << ", " << v1.y << ") - (" << v2.x << ", " << v2.y << ") = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";
        assert(result.x == 3.0f && result.y == 5.0f);
        std::cout << "Test result: Passed\n";
    }

    // Test case for scalar multiplication operator with integer
    {
        std::cout << "\nTest case: Scalar multiplication operator with integer\n";

        // Arrange
        g3d::vec2 v(2.0f, 3.0f);
        int scalar = 2;

        // Act
        g3d::vec2 result = v * scalar;

        // Assert
        std::cout << "(" << v.x << ", " << v.y << ") * " << scalar << " = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";
        assert(result.x == 4.0f && result.y == 6.0f);
        std::cout << "Test result: Passed\n";
    }

    // Test case for scalar multiplication operator with float
    {
        std::cout << "\nTest case: Scalar multiplication operator with float\n";

        // Arrange
        g3d::vec2 v(2.0f, 3.0f);
        float scalar = 1.5f;

        // Act
        g3d::vec2 result = v * scalar;

        // Assert
        std::cout << "(" << v.x << ", " << v.y << ") * " << scalar << " = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";
        assert(result.x == 3.0f && result.y == 4.5f);
        std::cout << "Test result: Passed\n";
    }

    // Test case for scalar division operator with float
    {
        std::cout << "\nTest case: Scalar division operator with float\n";

        // Arrange
        g3d::vec2 v(4.0f, 6.0f);
        float scalar = 1.5f;

        // Act
        g3d::vec2 result = v / scalar;

        // Assert

        std::cout << "(" << v.x << ", " << v.y << ") / " << scalar << " = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";

        // Define tolerance for floating-point comparison
        float tolerance = 0.00001f;
        assert(std::abs(result.x - 2.66667f) < tolerance);
        assert(std::abs(result.y - 4.0f) < tolerance);

        std::cout << "Test result: Passed\n";
    }

    // Test case for scalar division operator with int
    {
        std::cout << "\nTest case: Scalar division operator with int\n";

        // Arrange
        g3d::vec2 v(4.0f, 6.0f);
        int scalar = 2;

        // Act
        g3d::vec2 result = v / scalar;

        // Assert
        std::cout << "(" << v.x << ", " << v.y << ")" << scalar << " = ";
        std::cout << "(" << result.x << ", " << result.y << ")\n";

        // Define tolerance for floating-point comparison
        float tolerance = 0.00001f;
        assert(std::abs(result.x - 2) < tolerance);
        assert(std::abs(result.y - 3) < tolerance);

        std::cout << "Test result: Passed\n";
    }
    // All test cases passed
    std::cout << "\nAll test cases passed!\n";
    
    return 0;
 }