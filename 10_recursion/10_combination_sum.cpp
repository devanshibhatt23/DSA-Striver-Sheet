#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

void subs_with_sum_target(int idx, vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> v, int sum) {
    if(sum > target) return;

    if(idx >= candidates.size()) {
        if(sum == target) {
            res.push_back(v);
        }
        return;
    }

    v.push_back(candidates[idx]);
    sum += candidates[idx];

    subs_with_sum_target(idx,candidates,target,res,v,sum);

    v.erase(v.begin() + v.size() - 1);
    sum -= candidates[idx];

    subs_with_sum_target(idx+1,candidates,target,res,v,sum);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> empty;

    subs_with_sum_target(0, candidates, target, res, empty, 0);
    return res;
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &i : v) cin >> i;
    
    vector<vector<int>> ans = combinationSum(v,k);
    
    for(auto &i : ans) {
        for(int &j : i) cout << j << " ";
        cout << "\n";
    }
}