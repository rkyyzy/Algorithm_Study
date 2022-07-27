// AlgoStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "string\strings.h"

#define cout std::cout
#define endl std::endl

int main()
{
	// C++ 17
    // cout << _MSVC_LANG << endl;

	/*
	// KMP
	// Input: haystack = "hello", needle = "ll"
	// Output : 2
	KMP kmp;
	cout << "kmp test:" << endl;
	cout << kmp.strStr("hello", "ll") << endl;
	*/

	// Minimum Window Substring
	// Input: s = "ADOBECODEBANC", t = "ABC"
	// Output: "BANC"
	mws_solution mws;
	cout << "Minimum Window Substring test:" << endl;
	cout << mws.minWindow("ADOBECODEBANC", "ABC") << endl;

	return 0;
}
