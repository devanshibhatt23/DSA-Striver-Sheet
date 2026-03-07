#include <bits/stdc++.h>
#include <stack>
#define ll long long
using namespace std;

string removeOuterParentheses(string s) {
    string new_str = "";
    
    int sum = 0;
    for(char &ch : s) {
        if(ch == '(') {
            sum++;
            if(sum > 1) new_str.push_back('(');
        }
        else {
            sum--;
            if(sum > 0) new_str.push_back(')');
        }
    }

    return new_str;
}

int main() {
    string s;
    cin >> s;

    cout << removeOuterParentheses(s);
}