#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n);
    int break_it(int n);
};


bool Solution::isHappy(int n) {
    if (n < 10) {
        if (1 == n || 7 == n)
            return true;
        else
            return false;
    }
    else {
        n = break_it(n);
        return isHappy(n);
    }
}

int Solution::break_it(int n) {
    if (n < 10)
        return n * n;
    else
        return (n % 10) * (n % 10) + break_it(n / 10);
}

