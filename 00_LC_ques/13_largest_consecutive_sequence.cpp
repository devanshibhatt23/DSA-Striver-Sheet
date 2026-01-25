#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void solve(vector<int> &nums) {
    int n = nums.size();
    if(n==0) {
        cout << 0 << "\n";
        return;
    }

    unordered_set<int> s;
    for(int i : nums) s.insert(i);

    int ct = 0, ans = 0;

    for(int i : s) {
        if(s.find(i-1) == s.end()) {
            int k = i;

            while(s.find(k) != s.end()) {
                ct++;
                k++;
            }
            ans = max(ans,ct);
            ct = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    vector<int> v = {1,2,3,3,3,4,10,6,7,8,9};
    vector<int> v1 = {};

    solve(v1);
}