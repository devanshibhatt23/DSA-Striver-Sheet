#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int left = 0, right = n-k-1;
    int ans = INT_MAX, sum = 0;

    for(int i=0; i<=right; i++) sum += cardPoints[i];

    while(right < n) {
        ans = min(ans,sum);
        if(left != n) sum -= cardPoints[left];
        left++, right++;

        if(right != n) sum += cardPoints[right];
    }

    sum = 0;
    for(int &i : cardPoints) sum += i;

    return sum - ans;
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