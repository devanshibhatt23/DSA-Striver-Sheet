#include <bits/stdc++.h>
#include <string>
using namespace std;

// TC - O(N), SC - O(N) + O(N)
// Memoization 
int fibonacci(int n, vector<int> &dp) {
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}

// TC - O(N), SC - O(N)
// Tabulation
int fibonacci2(int n, vector<int> &dp) {
    dp[0] = 0, dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// optimizing space - O(1)
int fibonacci3(int n) {
    if(n <= 1) return n;

    int prev2 = 0, prev = 1;

    for(int i=2; i<=n; i++) {
        int ans = prev + prev2;
        prev2 = prev;
        prev = ans;
    }

    return prev;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp_1d_arr(n+1,-1);

    cout << fibonacci3(n);
}