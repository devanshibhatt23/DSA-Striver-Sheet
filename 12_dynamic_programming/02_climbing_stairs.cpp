#include <bits/stdc++.h>
#include <string>
using namespace std;

// memoization - tc - 2^n, sc - o(n)+o(n)
int recursion(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        dp[n] = 1;
        return 1;
    }

    if(dp[n] != -1) return dp[n];
    return dp[n] = (recursion(n-1,dp) + recursion(n-2,dp));
}

// tabulation - tc - o(n), sc - o(n)
int recursion(int n, vector<int> &dp) {
    dp[0] = 1, dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// optimising space - o(1)
int recursion(int n) {
    int prev2 = 1, prev = 1;

    for(int i=2; i<=n; i++) {
        int ans = prev+prev2;
        prev2 = prev;
        prev = ans;
    }

    return prev;
}

int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return recursion(n,dp);
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n);
}