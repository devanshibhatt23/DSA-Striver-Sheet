#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool checkValidString(string s) {
    int n = s.size();
    stack<int> left_bracks;
    stack<int> stars;

    for(int i=0; i<n; i++) {
        char ch = s[i];
        if(ch == '(') left_bracks.push(i);
        else if(ch == '*') stars.push(i);
        else {
            if(!left_bracks.empty()) left_bracks.pop();
            else if(!stars.empty()) stars.pop();
            else return false;
        }
    }

    while(!left_bracks.empty() && !stars.empty()) {
        if(stars.top() < left_bracks.top()) return false;
        else {
            stars.pop();
            left_bracks.pop();
        }
    }

    if(!left_bracks.empty()) return false;
    else return true;
}

int main() {
    cout << checkValidString("(*))");
}