#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s);
    int pow26(int);
};

int Solution::titleToNumber(string s) {
    int i = 0, total = 0;
    int length = s.length();
    while (i < length) {
        total += (s[length - i - 1] - 'A' + 1) * pow26(i);
        ++i;
    }
    return total;
}

int Solution::pow26(int n) {
    if (n == 0)
        return 1;
    else 
        return 26 * pow26(n - 1);
}