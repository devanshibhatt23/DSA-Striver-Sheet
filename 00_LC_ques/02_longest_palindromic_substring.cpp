#include <bits/stdc++.h>
using namespace std;

// TC - O(n^3), SC - O(1)

bool check(string s, int st, int end) {
    while(st < end) {
        if(s[st] == s[end]) {
            st++;
            end--;
        }
        else return 0;
    }

    return 1;
}

string bruteForce(string s) {
    int n = s.size();

    for(int length=n; length>0; length--) {
        for(int start=0; start<=n-length; start++) {
            if(check(s,start,start+length)) {
                return s.substr(start,length);
            }
        }
    }

    return "";
}

// TC - O(n^2) SC - O(n^2)

string dpApproach(string s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n,0));
    pair<int,int> substr;

    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
        substr = {i,i};
    }

    for(int i=1; i<n; i++) {
        if(s[i-1] == s[i]) {
            dp[i-1][i] = 1;
            substr = {i-1,i};
        }
    }

    for(int diff=2; diff<n; diff++) {
        for(int i=0; i<n-diff; i++) {
            int j = i+diff;

            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
                substr = {i,j};
            }
        }
    }

    int i = substr.first, j = substr.second;
    return s.substr(i,j-i+1);
}

// TC - O(n^2) SC - O(1)

string expand(string s, int i, int j) {
    while(i>=0 && j<s.size() && s[i] == s[j]) {
        i--;
        j++;
    }

    return s.substr(i+1,j-i-1);
}

string longestPalindrome(string s) {
    int n = s.size();
    string ans = "";

    for(int i=0; i<n; i++) {
        string substr = expand(s,i,i);

        if(substr.size() > ans.size()) {
            ans = substr;
        }
    }

    for(int i=0; i<n-1; i++) {
        string substr = expand(s,i,i+1);

        if(substr.size() > ans.size()) {
            ans = substr;
        }
    }

    return ans;
}