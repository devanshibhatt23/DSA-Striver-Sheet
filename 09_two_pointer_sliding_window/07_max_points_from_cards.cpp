#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total = 0, ans = 0;
    int left = 0, right = n-k+1;

    for(int i=0; i<=n-k; i++) total += cardPoints[i];

    while(right < n) {
        ans = max(ans,total);
        total -= cardPoints[left];
        total += cardPoints[right];
        left++, right++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int k;
    cin >> k;

    cout << maxScore(nums,k);
}