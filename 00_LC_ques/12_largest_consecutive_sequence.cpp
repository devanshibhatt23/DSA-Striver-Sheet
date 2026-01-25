#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums) {
    int n = nums.size();
    if(n==0) {
        cout << 0 << "\n";
        return;
    }

    sort(nums.begin(), nums.end());

    int ct = 1, ans = 1;
    int num = nums[0];

    for(int i=1; i<n; i++) {
        if(nums[i] == num+1) {
            ct++;
            num++;
        }
        else if(nums[i] == num) continue;
        else {
            ct = 1;
            num = nums[i];
        }
        ans = max(ans, ct);
    }

    cout << ans << endl;
}

int main() {
    vector<int> v = {1,2,3,3,3,4,10,7,8,9};

    solve(v);
}