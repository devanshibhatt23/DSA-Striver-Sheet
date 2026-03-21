#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

bool subs_sum_k(int idx, vector<int> vec, vector<int> v, int sum, int k) {
    if(idx >= vec.size()) {
        if(sum == k) {
            for(int &i : v) cout << i << " ";
            cout << "\n";
            return true;
        }
        return false;
    }

    v.push_back(vec[idx]);
    sum += vec[idx];

    if(subs_sum_k(idx+1,vec,v,sum,k) == true) return true;

    v.erase(v.begin() + v.size() - 1);
    sum -= vec[idx];

    if(subs_sum_k(idx+1,vec,v,sum,k) == true) return true;

    return false;
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> empty(0);

    subs_sum_k(0,v,empty,0,k);
}