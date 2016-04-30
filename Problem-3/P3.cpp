#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s) {
    int ascii[128], count, j = 0;
    int length = 0;
    for (int i = 0; i < 128; i++) {
        ascii[i] = 0;
    }

    for (int i = 0; i < s.length(); i++) {
        count = 1;
        ascii[s[i]] = 1;
        cout << s[i];
        j = i + 1;
        while (ascii[s[j]] == 0 && j < s.length()) {
            ascii[s[j]] = 1;
            cout << s[j];
            count++;
            j++;
        }
        if (count > length) {
            length = count;
        }

        for (int i = 0; i < 128; i++) {
            ascii[i] = 0;
        }
    }

    return length;
}
