#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b);
};

string Solution::addBinary(string a, string b) {
    string ans = "";
    int mid, i, j;
    if (0 == a.length()) {
        if (0 == b.length()) {
            return "0";
        }
        else {
            return b;
        }
    }
    else if (0 == b.length()) {
        return a;
    }
    i = a.length() - 1;
    j = b.length() - 1;
    ans = "0";
    while (i >= 0 && j >= 0) {
        mid = a[i] + b[j] - '0' - '0';
        ans[0] = mid + ans[0];
        if (ans[0] > '1') {
            ans[0] -= 2;
            ans = "1" + ans;
        }
        else {
            ans = "0" + ans;
        }
        --i;
        --j;
    }
    if (i < 0) {
        while (j >= 0) {
            ans[0] = ans[0] + b[j] - '0';
            if (ans[0] > '1') {
                ans[0] -= 2;
                ans = "1" + ans;
            }
            else {
                ans = "0" + ans;
            }
            --j;
        }
    }
    else if (j < 0) {
        while (i >= 0) {
            ans[0] = ans[0] + a[i] - '0';
            if (ans[0] > '1') {
                ans[0] -= 2;
                ans = "1" + ans;
            }
            else {
                ans = "0" + ans;
            }
            --i;
        }
    }
    if (ans[0] == '0') {
        ans.erase(0, 1);
    }
    return ans;
}
