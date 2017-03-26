/**
 * @file stack push tests
 *
 * @version 1.0
 * @date 3/23/2017
 * @author Donald Harmon II
 *
 * Tests for stack class push, uses top(), empty(), & stack()
 *
 */

#include <iostream>
#include <cassert>
#include "stack.hpp"
#include "../string/string.hpp"

//===========================================================================
int main ()
{
// SINGLE PUSH FOR MULTIPLE TYPES
	{
		// Setup Fixture
		stack<int> stk;
		// Test
		stk.push(42);
		// Verify
		assert(stk.top()==42);
	}
	{
		// Setup Fixture
		stack<String> stk;
		// Test
		stk.push("I'm a string!");
		// Verify
		assert(stk.top()=="I'm a string!");
	}
	{
		// Setup Fixture
		stack<char> stk;
		// Test
		stk.push('\n');
		// Verify
		assert(stk.top()=='\n');
	}
	{
		// Setup Fixture
		stack<char *> stk;
		// Test
		stk.push((char *)"I'm a character array!");
		// Verify
		assert(stk.top()=="I'm a character array!");
	}
	{
		// Setup Fixture
		stack<float> stk;
		// Test
		stk.push(42.42);
		// Verify
		std::cout << stk.top() << std::endl;
		assert(stk.top()==42.42f);
	}
	{
		// Setup Fixture
		stack<double> stk;
		// Test
		stk.push(42.4242);
		// Verify
		assert(stk.top()==42.4242);
	}
	{
		// Setup Fixture
		stack<bool> stk;
		// Test
		stk.push(true);
		// Verify
		assert(stk.top()==true);
	}
	{
		// Unicode Sailboat Test!
		// Setup Fixture
		stack<wchar_t> stk;
		// Test
		stk.push(L'⛵');
		// Verify
		assert(stk.top()==L'⛵');
	}
// MULTIPLE PUSHES / POP - PUSH TESTS
	// int TESTS
	{
		// Setup Fixture
		stack<int> stk;
		// Test
		stk.push(42);
		// Verify
		assert(stk.top()==42);
	}




	std::cout << "Done testing push" << std::endl;

}