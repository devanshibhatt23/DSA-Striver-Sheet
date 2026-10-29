#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;

        for(int i=0; i<n; i++) {
            int temp = temperatures[i];

            while(!st.empty() && temp > st.top().first) {
                auto [val,idx] = st.top();
                st.pop();

                ans[idx] = i-idx;
            }

            st.push({temp,i});
        }

        return ans;
    }
};