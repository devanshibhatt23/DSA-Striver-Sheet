#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

void generate(string curr, int n, int open_ct, int close_ct, vector<string> &res) {
    if(curr.size() == 2*n) {
        res.push_back(curr);
        return;
    }

    if(open_ct < n) generate(curr + '(', n, open_ct+1, close_ct, res);
    if(close_ct < open_ct) generate(curr + ')', n, open_ct, close_ct+1, res);
}

vector<string> generate_all_subs(int n) {
    vector<string> res;

    generate("",n,0,0,res);
    return res;
}

vector<string> generateParenthesis(int n) {
    return generate_all_subs(n);
}