#include <iostream>
#include <cstring>

using namespace std;

//http://www.sanfoundry.com/cpp-program-implement-kruth-morris-patt-algorithm-kmp/


void preA(string pattern, int f[]);

//check whether target string contains pattern
bool KMP(string pattern, string target);
