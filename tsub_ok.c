/*
 * author: Marcio Porto
 * COMP 240-02 - HW2
 */

#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * Determines whether arguments can be subtracted without overflow
 * Input = Two numbers, x and y
 * Output = Whether x - y overflows. Returns 1 if no overflow, and 0 if there's overflow
 */
int tsub_ok(int x, int y) {
    int subt = x - y;
    
    /*
     * If x is positive and y is negative, x-y becomes x-(-y), which is just x+y
     * In this case, if subt is positive, negative_overflow should be true(1)
     */
    int negative_overflow = (x < 0 && y >= 0) && subt > 0;
    
    /*
     * If x is negative and y is positive, x-y becomes x-(-y), which is just x+y
     * In this case, if subt is negative, positive_overflow should be true(1)
     */
    int positive_overflow = (x >= 0 && y < 0) && subt < 0;
    
    return !positive_overflow && !negative_overflow;    
}

// Test cases that demonstrate correctness of the function
int main() {
    
    int intMax = INT_MAX;
    int intMin = INT_MIN;
    
    // These following tests should overflow:
    assert(tsub_ok(intMax, intMin) == 0);       // tests when x is maximum possible value and y is minimum possible
    assert(tsub_ok(intMin, intMax) == 0);       // tests when x is minimum possible value and y is maximum possible
    assert(tsub_ok(intMax, -1) == 0);           // tests when x is maximum possible value and y is -1
    assert(tsub_ok(intMin, 1) == 0);            // tests when x is minimum possible value and y is 1
    
    // These following tests should not overflow:
    assert(tsub_ok(5, 3) == 1);                 //
    assert(tsub_ok(-1, 1) == 1);                //
    
    return 0;    
}