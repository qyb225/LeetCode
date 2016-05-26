#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num);
};

int Solution::addDigits(int num) {
    if (num < 10)
        return num;
    else 
        return addDigits((num % 10) + addDigits(num / 10));
}
