#include <bits/stdc++.h>
using namespace std;

int func(int idx, int prev_idx, vector<vector<int>> &matrix) {
    if(idx == 0) {
        int ans = 0;

        for(int i=0; i<3; i++) {
            if(i != prev_idx) {
                ans = max(ans,matrix[idx][i]);
            }
        }

        return ans;
    }

    int ans = 0;

    for(int i=0; i<3; i++) {
        if(i != prev_idx) {
            ans = max(ans, matrix[idx][i] + func(idx-1,i,matrix));
        }
    }

    return ans;
}

int memoization(int idx, int prev_idx, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(idx == 0) {
        int ans = 0;

        for(int i=0; i<3; i++) {
            if(i != prev_idx) {
                ans = max(ans,matrix[idx][i]);
            }
        }

        return ans;
    }

    if(dp[idx][prev_idx] != -1) return dp[idx][prev_idx];

    int ans = 0;

    for(int i=0; i<3; i++) {
        if(i != prev_idx) {
            ans = max(ans, matrix[idx][i] + memoization(idx-1,i,matrix,dp));
        }
    }

    return dp[idx][prev_idx] = ans;
}

int tabulation(int n, int prev_idx, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    for(int i=0; i<n; i++) {
        if(i == 0) {
            dp[0][0] = max(matrix[0][1], matrix[0][2]);
            dp[0][1] = max(matrix[0][0], matrix[0][2]);
            dp[0][2] = max(matrix[0][1], matrix[0][0]);
            dp[0][3] = max(matrix[0][1], max(matrix[0][1], matrix[0][2]));
        }
        else {
            for(int j=0; j<4; j++) {
                int maxi = 0;

                for(int k=0; k<3; k++) {
                    if(j != k) {
                        maxi = max(maxi, matrix[i][k] + dp[i-1][k]);
                    }
                }
                dp[i][j] = maxi;
            }

            return dp[n-1][3];
        }
    }
}

int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int> (4,-1));

    cout << memoization(n-1,3,matrix,dp);
}