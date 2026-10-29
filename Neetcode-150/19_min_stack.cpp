#include <bits/stdc++.h>
#include <stack>
using namespace std;

// TC - O(1), SC - O(n) - 2 stacks
class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(!minStack.empty()) {
            int val2 = minStack.top();
            
            minStack.push(min(val,val2));
        }

        else {
            minStack.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

// TC - O(1), SC - O(n) - 1 stack
class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push(0);
            mini = val;
        }
        else {
            st.push(val-mini);
            if(val < mini) {
                mini = val;
            }
        }
    }
    
    void pop() {
        long long val = st.top();
        st.pop();

        if(val < 0) {
            mini = mini - val;
        }
    }
    
    int top() {
        long long val = st.top();

        if(val < 0) {
            return int(mini);
        }

        return val + mini;
    }
    
    int getMin() {
        return int(mini);
    }
};