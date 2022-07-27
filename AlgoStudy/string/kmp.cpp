#include "strings.h"

/***********************************************************************************************
 *                              Knuth¨CMorris¨CPratt algorithm                                   *
 * consistent to C's strstr()                                                                  *
 *                                                                                             *
 * INPUT:      two strings needle and haystack                                                 *
 *                                                                                             *
 * OUTPUT:     the index of the first occurrence of needle in haystack, or -1                  *
 *             if needle is not part of haystack.                                              *
 *                                                                                             *
 * CONSTRAINT: 1 <= haystack.length, needle.length                                             *
               haystack and needle consist of only lowercase English characters.               *
 * youtube: https://www.youtube.com/watch?v=V5-7GzOfADQ                                        *
 *                                                                                             *
 *=============================================================================================*/
// LC: 28 Implement strStr()

int KMP::strStr(std::string haystack, std::string needle) {
	int m = haystack.size(), n = needle.size();
	std::vector<int> lps = kmpProcess(needle);
	int i = 0, j = 0;
	while (i < m) {
		if (haystack[i] == needle[j]) {
			i++, j++;
		}
		if (j == n) {
			return i - j;
		}
		if (i < m && haystack[i] != needle[j]) {
			j ? j = lps[j - 1] : i++;
		}
	}
	return -1;
}

std::vector<int> KMP::kmpProcess(std::string needle) {
	int n = needle.size();
	std::vector<int> lps(n, 0);
	int i = 1, len = 0;
	while (i < n) {
		if (needle[i] == needle[len]) {
			lps[i++] = ++len;
		}
		else if (len) {
			len = lps[len - 1];
		}
		else {
			lps[i++] = 0;
		}
	}
	return lps;
}