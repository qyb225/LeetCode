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
    int i = 0, j = s.length() - 1;
    
    while (i < s.length() - ans.length()) {
        j = s.length() - 1;
        while (j >= i) {
            if (s[i] == s[j]) {
                if (isPalindrome(s.substr(i + 1, j - i - 1))) {
                    if (j - i + 1 > ans.length()) {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
            j--;
        }
        i++;
    }
    return ans;
}

bool Solution::isPalindrome(string s) {
    if (s.length() == 1 || s.length() == 0) {
        return true;
    }
    else {
        return (s[0] == s[s.length() - 1]) && isPalindrome(s.substr(1, s.length() - 2));
    }
}

int main() {
    Solution p;
    string s = "dabcbab";
    cout << p.longestPalindrome(s) << endl;
    return 0;
}