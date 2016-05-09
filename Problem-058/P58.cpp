#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s);
};

int Solution::lengthOfLastWord(string s) {
    int count = 0;
    int length = s.length() - 1;
    while (s[length] == ' ') {
        --length;
    }
    if (length < 0) {
        return 0;
    }
    for (int i = length; s[i] != ' ' && i >= 0; --i) {
        ++count;
    }
    return count;
}
