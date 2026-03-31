#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

class Solution {
public:
    void combinations(int idx, string s, string &digits, vector<string> &res, vector<string> &combs) {
        if(idx >= digits.size()) {
            res.push_back(s);
            return;
        }

        int digit = digits[idx] - '0';

        for(int i=0; i<combs[digit].size(); i++) {
            combinations(idx+1, s+combs[digit][i], digits, res, combs);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string empty = "";

        vector<string> combs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        combinations(0,empty,digits,res,combs);
        return res;
    }
};