// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4); 
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi("123456789");

        // Test
        int digit = bi[8];
        int digit_two = bi[7];
        int digit_thr = bi[6];
        int digit_four = bi[5];
        int digit_five = bi[4];
        int digit_six = bi[3];
        int digit_sev = bi[2];
        int digit_eight = bi[1];
        int digit_nine = bi[0];

        // Verify
        assert(bi == 123456789);
        assert(digit == 1);
        assert(digit_two == 2);
        assert(digit_thr == 3);
        assert(digit_four == 4);
        assert(digit_five == 5);
        assert(digit_six == 6);
        assert(digit_sev == 7);
        assert(digit_eight == 8);
        assert(digit_nine == 9);
    }
    {
        // Setup
        bigint bi(999999);

        // Test 
        bi[0] = 3;
        bi[1] = 4;
        bi[2] = 5;
        bi[3] = 6;
        bi[4] = 7;
        bi[5] = 8;

        // Verify
        assert(bi == 876543);
    }
    {
        // Setup
        bigint bi;

        // Test
        bi[255] = 9;

        // Verify
        assert(bi[255]==9);
    }
    {
        // Setup
        bigint bi(99);

        // Test
        int digit = bi[0] * bi[1];

        // Verify
        std::cout << digit << std::endl;
        assert(digit == 81);
    }

    // Unit test for const [] operator
    {
        // Setup
        const bigint bi("1234");

        // Test
        int digit = bi[0];

        // Verify
        assert(digit == 4);
    }

    //Added test cases!!

    std::cout << "Done testing subscript." << std::endl;

}
