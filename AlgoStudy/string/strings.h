#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class KMP {
public:
	int strStr(std::string haystack, std::string needle);
private:
	std::vector<int> kmpProcess(std::string needle);
};

class mws_solution {
public:
	std::string minWindow(std::string s, std::string t);
};