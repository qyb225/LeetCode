#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle) {
    int i;
    i = haystack.find(needle);
    if (i != haystack.npos) {
        return (int)i;
    }
    else {
        return -1;
    }
}
