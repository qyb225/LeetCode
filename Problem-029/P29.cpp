#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor);
};

int Solution::divide(int dividend, int divisor) {
    if (0 == divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int sign = 1;
    if ((dividend < 0) ^ (divisor < 0) == 1)
        sign = -1;
    long long dvs = (dividend < 0)? (long long)dividend * -1: (long long)dividend;
    long long dir = (divisor < 0)? (long long)divisor * -1: (long long)divisor;
    int ans = 0;
    
    while (dvs >= dir) {
        long long multi = 1;
        long long temp = dir;
        while (dvs >= (temp << 1)) {
            temp <<= 1;
            multi <<= 1;
        }
        dvs -= temp;
        ans += multi;
    }
    return ans * sign;
}