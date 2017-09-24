#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n);
    vector<string> generateParenthesis(int n, vector<vector<string> >&);
    void multiply(vector<string> a, vector<string> b, vector<string>& ans);
};

int main() {
    Solution p;
    vector<string> ans = p.generateParenthesis(10);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    return 0;
}

vector<string> Solution::generateParenthesis(int n) {
    vector<vector<string> > bucks;
    return generateParenthesis(n, bucks);
}


vector<string> Solution::generateParenthesis(int n, vector<vector<string> >& bucks) {
    if (n < bucks.size())
        return bucks[n];
    else if (n < 1) {
        vector<string> v;
        v.push_back("");
        bucks.push_back(v);
        return v;
    }
    else if (1 == n) {
        vector<string> v;
        v.push_back("()");
        bucks.push_back(v);
        return v;
    }
    else {
        vector<string> ans;
        ans = generateParenthesis(n - 1, bucks);
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = "(" + ans[i];
            ans[i] += ")";
        }
        for (int i = n - 1, j = 1; i >= j; --i, ++j) {
            multiply(generateParenthesis(i, bucks), generateParenthesis(j, bucks), ans);
        }
        bucks.push_back(ans);
        return ans;
    }
}

void Solution::multiply(vector<string> a, vector<string> b, vector<string>& ans) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (ans.end() == find(ans.begin(), ans.end(), a[i] + b[j]))
                ans.push_back(a[i] + b[j]);
            if (ans.end() == find(ans.begin(), ans.end(), b[j] + a[i]))
                ans.push_back(b[j] + a[i]);
        }
    }
}