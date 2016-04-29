#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x);
};

int pow10(int);
int my_abs(int);

int pow10(int n) {
    if (0 == n) {
        return 1;
    }
    else {
        return 10 * pow10(n - 1);
    }
}

int Solution::reverse(int x) {
    int mid, n = 0, count = 0;
    int judge = 1;
    int = 0;

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
    return judge * ans;       
}

int my_abs(int a) {
    if (a < 0) {
        a = -1 * a;
    }
    return a;
}
