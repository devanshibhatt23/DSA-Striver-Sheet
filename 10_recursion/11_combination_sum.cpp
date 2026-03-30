#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

void func(int idx, int target, vector<int> &empty, vector<int> &candidates, vector<vector<int>> &res) {
    int n = candidates.size();

    if(target == 0) {
        res.push_back(empty);
        return; 
    }

    for(int i=idx; i<n; i++) {
        if(i != idx && candidates[i] == candidates[i-1]) continue;

        if(candidates[i] > target) break;

        empty.push_back(candidates[i]);

        func(i+1, target-candidates[i], empty, candidates, res);
        empty.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> empty;

    sort(candidates.begin(), candidates.end());

    func(0,target,empty,candidates,res);

    return res;
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &i : v) cin >> i;
    
    vector<vector<int>> ans = combinationSum2(v,k);
    
    for(auto &i : ans) {
        for(int &j : i) cout << j << " ";
        cout << "\n";
    }
}