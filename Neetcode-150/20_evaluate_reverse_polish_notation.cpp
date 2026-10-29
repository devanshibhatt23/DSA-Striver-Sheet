#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string plus = "+", minus = "-", mult = "*", div = "/";

        for(string &str : tokens) {
            if(str == plus) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(a+b);
            }
            else if(str == minus) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b-a);
            }
            else if(str == mult) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(a*b);
            }
            else if(str == div) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b/a);
            }
            else {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};