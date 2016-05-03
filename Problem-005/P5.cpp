#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string);
    bool isPalindrome(string);
};

string Solution::longestPalindrome(string s) {
    string ans = "";
    if (s.length() <= 1) {
        return s;
    }
    ans = s[0];

    for (int i = 0; i < s.length() - 1; i++) {
        int j = 0;
        if (s[i - 1] == s[i + 1]) {
            while (i + j < s.length() && i - j >= 0) {
                if (s[i + j] == s[i - j]) {
                    if (2 * j + 1 > ans.length()) {
                        ans = s.substr(i - j, 2 * j + 1);
                    }
                    j++;
                }
                else {
                    break;
                }
            }
        }
        j = 0;
        if (s[i] == s[i + 1]){
            while (i + 1 + j < s.length() && i - j >= 0) {
                if (s[i + 1 + j] == s[i - j]) {
                    if (2 * j + 2 > ans.length()) {
                        ans = s.substr(i - j, 2 * j + 2);
                    }
                    j++;
                }
                else {
                    break;
                }
            }
        }
    }
    return ans;
}
