// bigint Test Program
//
// Tests:  times_digit, uses ==
//
#include <iostream>
#include <cassert>
#include <climits>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == 3); 
    }
    {
        // Adding test case
        // Setup fixture
        bigint bi(12345);

        // Test 
        bi = bi.times_digit(0);

        // Verify
        assert(bi == 0);
    }
    {
        // Setup fixture
        bigint bi(1234);

        // Test
        bi = bi.times_digit(2);

        // Verify
        assert(bi == 2468);
    }
    {
        // Setup fixture
        bigint bi(55555);

        // Test
        bi = bi.times_digit(2);

        // Verify
        assert(bi == 111110);
    }
    {
        // Setup fixture
        bigint bi(55555);

        // Test
        bi = bi.times_digit(3);

        // Verify
        assert(bi == 166665);
    }
    {
        // Setup fixture
        bigint bi(55555);

        // Test
        bi = bi.times_digit(7);

        // Verify
        assert(bi == 388885);
    }
    {
        // Setup fixture
        bigint bi(987654);

        // Test
        bi = bi.times_digit(5);

        // Verify
        assert(bi == 4938270);
    }
    {
        // Setup fixture
        bigint bi(9876);

        // Test
        bi = bi.times_digit(9);

        // Verify
        assert(bi == 88884);
    }
    {
        // Setup fixture
        bigint bi(999999);

        // Test 
        bi = bi.times_digit(9);

        // Verify
        assert(bi == 8999991);
    }
    {
        // Setup fixture
        bigint bi(INT_MAX);

        // Test
        bi = bi.times_digit(5);

        // Verify
        assert(bi == "10737418235");
    }
    {
        // Setup fixture
        bigint bi("1234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234123412341234");

        // Test
        bi = bi.times_digit(2);

        // Verify
        assert(bi == "2468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468246824682468");
    }
    {
        // Adding test case
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test
        bi = bi.times_digit(1);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    }
    {
        // Adding test case
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test
        bi = bi.times_digit(2);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998");
    }
    {
        // Adding test case
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test
        bi = bi.times_digit(9);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999991");
    }
    //Added test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;

}
