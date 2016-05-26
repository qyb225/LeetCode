#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str);
    void word_break(string, string *);
};

bool Solution::wordPattern(string pattern, string str) {
    int length = pattern.length();
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ')
            count += 1;
    }
    if (length != count + 1)
        return false;
    string * p = new string[length];
    word_break(str, p);

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pattern[i] != pattern[j]) {
                if (p[i] == p[j])
                    return false;
            }
        }

        for (int j = i + 1; j < length; ++j) {
            if (pattern[i] == pattern[j]) {
                if (p[i] != p[j])
                    return false;
            }
        }
    }

    delete [] p;
    return true;
}

void Solution::word_break(string str, string *p) {
    int i = 0;
    int count = 0;
    string mid_ans = "";
    while (i < str.length()) {
        if (str[i] != ' ' && i != str.length() - 1)
            mid_ans += str[i];
        else if (i == str.length() - 1) {
            mid_ans += str[i];
            p[count++] = mid_ans;
            mid_ans = "";
        }
        else {
            p[count++] = mid_ans;
            mid_ans = "";
        }
        ++i;
    }
}