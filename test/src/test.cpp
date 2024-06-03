#include "vector_test.h"

int main() {
    VectorTest test;

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

    return 0;
 }