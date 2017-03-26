/**
 * @file stack default_ctor tests
 *
 * @version 1.0
 * @date 3/23/2017
 * @author Donald Harmon II
 *
 * Tests for stack class default ctor, uses empty()
 *
 */

#include <iostream>
#include <cassert>
#include "../string/string.hpp"
#include "stack.hpp"

//===========================================================================
int main ()
{
	// Testing empty stack: String and built in types
	{
		// Setup / Test
		stack<int> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<String> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<char> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<char *> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<float> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<double> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<bool> stk;
		// Verify
		assert(stk.empty());
	}
	{
		// Setup / Test
		stack<wchar_t> stk;
		// Verify
		assert(stk.empty());
	}


	std::cout << "Done testing default constructor" << std::endl;

}