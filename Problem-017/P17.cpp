#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits);
    vector<string> multiply(vector<string>&, string);
};

vector<string> Solution::letterCombinations(string digits) {
    string letter[10];
    letter[0] = "";
    letter[1] = "";
    letter[2] = "abc";
    letter[3] = "def";
    letter[4] = "ghi";
    letter[5] = "jkl";
    letter[6] = "mno";
    letter[7] = "pqrs";
    letter[8] = "tuv";
    letter[9] = "wxyz";
    vector<string> ans;
    for (int i = 0; i < digits.size(); ++i) {
        ans = multiply(ans, letter[digits[i] - '0']);
    }
    return ans;
}

vector<string> Solution::multiply(vector<string>& a, string b) {
    vector<string> ans;
    if (a.size() == 0) {
        for (int i = 0; i < b.size(); ++i) {
            char tmp = b[i];
            string c = "";
            c += tmp;
            ans.push_back(c);
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            ans.push_back(a[i] + b[j]);
        }
    }
    return ans;
}