#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows);
};

string Solution::convert(string s, int numRows) {

	int i = 0, j = 0;

	if (numRows <= 1) {
		return s;
	}
	string * ans = new string[numRows];
	string finally_ans;

	while (i < s.length()) {
		while (j < numRows) {
			if (i >= s.length()) {
				break;
			}
			ans[j] += s[i];
			j++;
			i++;
		}
		j -= 2;
		while (j > 0) {
			if (i >= s.length()) {
				break;
			}
			ans[j] += s[i];
			j--;
			i++;
		}
	}
	for (int i = 0; i < numRows; i++) {
		finally_ans += ans[i];
	}

	delete [] ans;
	return finally_ans;
}
