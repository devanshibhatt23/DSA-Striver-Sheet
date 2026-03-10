#include <bits/stdc++.h>
#include <stack>
#define ll long long
using namespace std;

int maxDepth(string s) {
    // stack<char> st;
    int depth = 0, ans = 0;

    for(char &ch : s) {
        if(ch == '(') {
            // st.push(ch);
            depth++;
        }
        else if(ch == ')') {
            // if(!st.empty()) {
                // st.pop();
                ans = max(ans,depth);
                depth--;
            // }
        }
    }

    ans = max(ans, depth);
    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << maxDepth(s);
}