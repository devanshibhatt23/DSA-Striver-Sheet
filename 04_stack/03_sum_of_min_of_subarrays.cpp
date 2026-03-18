#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define f(i,s,e) for(int i=s; i<e; i++)
#define en cout << "\n"
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int k = 1e9 + 7;

    vector<int> next_smaller(n), prev_smaller(n);
    
    stack<pair<int,int>> st, st2;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && (st.top()).first > arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            next_smaller[i] = n;
        }
        else next_smaller[i] = (st.top()).second;

        st.push({arr[i], i});
    }

    for(int i=0; i<n; i++) {
        while(!st2.empty() && (st2.top()).first >= arr[i]) {
            st2.pop();
        }
        if(st2.empty()) prev_smaller[i] = -1;
        else prev_smaller[i] = (st2.top()).second;

        st2.push({arr[i], i});
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        int right = next_smaller[i] - i;
        int left = i - prev_smaller[i];

        ans = (ans + (arr[i]*1LL*left*right) % k) % k;
    }
    return ans;
}

int main() {
    vector<int> v = {71,55,82,55};
    int ans = sumSubarrayMins(v);
    cout << ans << "\n";
}