// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include <climits>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      // Adding test case
      // Setup fixture
      bigint left(9);
      bigint right(6);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 9);
      assert(right == 6);
      assert(result == 15);
    }
    {
      // Setup fixture
      bigint left(2345);
      bigint right(2345);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 2345);
      assert(right == 2345);
      assert(result == 4690);


    }
    {
      // Adding test case
      // Setup fixture
      bigint left(999);
      bigint right("4000900123");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 999);
      assert(right == "4000900123");
      assert(result == "4000901122");
    }
    {
      // Adding test case
      // Setup fixture
      bigint left("99999999999999999999");
      bigint right("99999999999999999999");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "99999999999999999999");
      assert(right == "99999999999999999999");
      assert(result == "199999999999999999998");
    }
    {
      // Adding test case
      // Setup fixture
      bigint left(INT_MAX);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == INT_MAX);
      assert(right == 1);
      assert(result == "2147483648");
    }
    {
      // Adding test case
      // Setup fixture
      bigint left(1);
      // 256 9's
      bigint right("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      bigint result;

      // Test by adding 1 to 256 9's
      result = left + right;

      std::cout << result << std::endl;
      std::cout << "^ should be 0" << std::endl;

      //Verify result is 0
      assert(left == 1);
      assert(right == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      assert(result==0);
    }
   

    
    //Added test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
}

