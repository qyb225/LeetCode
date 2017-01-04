#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x);
    long long pow10(long long int);
    long long my_abs(long long int);
};

int Solution::reverse(int x) {
    long long mid, n = 0, count = 0;
    long long judge = 1;
    long long ans = 0;

    if (x < 0) {
        judge = -1;
    }
    x = my_abs(x);
    while (count >= 0) {
        if (x / pow10(count) == 0) {
            break;
        }
        count++;
    }
    count -= 1;
    while (x > 0) {
        mid = x / pow10(count);
        ans += mid * pow10(n++);
        x -= mid * pow10(count);
        count--;
    }
    ans = judge * ans;
    return (ans > INT_MAX || ans < INT_MIN)? 0: ans;       
}

long long Solution::my_abs(long long int a) {
    if (a < 0) {
        a = -1 * a;
    }
    return a;
}

long long Solution::pow10(long long int n) {
    if (0 == n) {
        return 1;
    }
    else {
        return 10 * pow10(n - 1);
    }
}

