#include "vec2_test.h"
#include "vec3_test.h"

void test_vec2();

void test_vec3();

int main() {
    
    test_vec3();

    return 0;
 }

void test_vec2()
{
    Vec2Test test;

    test.additionTest(vec2(1.0f, 2.0f), vec2(3.0f, 4.0f), vec2(4.0f, 6.0f));

    test.subtractionTest(vec2(5.0f, 8.0f), vec2(2.0f, 3.0f), vec2(3.0f, 5.0f));

    test.scalarMultiplicationTest(vec2(2.0f, 3.0f), 2, vec2(4.0f, 6.0f));

    test.scalarDivisionTest(vec2(4.0f, 6.0f), 2, vec2(2.0f, 3.0f));

    test.normalizationTest(vec2(3.0f, 4.0f), vec2(0.6f, 0.8f));

    test.magnitudeTest(vec2(3.0f, 4.0f), 5.0f);

    test.dotProductTest(vec2(3, 4), vec2(2, -1), 2);

    test.crossProductTest(vec2(2, 3), vec2(-1, 2), 7);

    // Run all tests
    test.run();
}

void test_vec3()
{
    Vec3Test test;

    test.additionTest(vec3(1.0f, 2.0f, 3.0f), vec3(3.0f, 4.0f, 5.0f), vec3(4.0f, 6.0f, 8.0f));

    test.subtractionTest(vec3(5.0f, 8.0f, 10.0f), vec3(2.0f, 3.0f, 4.0f), vec3(3.0f, 5.0f, 6.0f));

    test.scalarMultiplicationTest(vec3(2.0f, 3.0f, 4.0f), 2, vec3(4.0f, 6.0f, 8.0f));

    test.scalarDivisionTest(vec3(4.0f, 6.0f, 8.0f), 2, vec3(2.0f, 3.0f, 4.0f));

    test.normalizationTest(vec3(3.0f, 4.0f, 5.0f), vec3(0.424264f, 0.565685f, 0.707107f));

    test.magnitudeTest(vec3(3.0f, 4.0f, 5.0f), 7.071068f);

    test.dotProductTest(vec3(3, 4, 5), vec3(2, -1, 3), 17);

    test.crossProductTest(vec3(2, 3, 4), vec3(-1, 2, 1), vec3(-5, -6, 7));

    // Run all tests
    test.run();
}
