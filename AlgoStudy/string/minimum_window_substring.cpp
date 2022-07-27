#include "strings.h"

/***********************************************************************************************
 *                              Minimum Window Substring                                       *
 * Given two strings s and t of lengths m and n respectively,								   *
 * return the minimum window substring of s such that every character in t					   *
 * (including duplicates) is included in the window. If there is no such substring,            *
 * return the empty string "".                                                                 *
 *                                                                                             *
 * INPUT:      two strings s and t                                                             *
 *                                                                                             *
 * OUTPUT:     minimum window substring of s                                                   *
 *                                                                                             *
 * CONSTRAINT: 1 <= s.length, t.length <= 105												   *
 * s and t consist of uppercase and lowercase English letters.								   *
 *                                                                                             *
 *=============================================================================================*/
 // LC: 76 Minimum Window Substring

std::string mws_solution::minWindow(std::string s, std::string t) {
	std::unordered_map <char, int> letters;
	for (char c : t) {
		letters[c]++;
	}
	int low = 0, min_start = 0, min_length = INT_MAX, count = 0;
	for (int high = 0; high < s.length(); high++) {
		if (letters[s[high]] > 0) {
			// letter exist in t
			count++;
		}
		letters[s[high]]--;
		if (count == t.length()) {
			while (letters[s[low]] < 0) {
				letters[s[low]]++;
				low++;
			}

			if (high - low + 1 < min_length) {
				min_start = low;
				min_length = high - low + 1;
			}
		}

	}
	return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
}