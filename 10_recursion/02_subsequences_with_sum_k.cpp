#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

void subs_sum_k(int idx, vector<int> vec, vector<int> v, int sum, int k) {
    if(idx >= vec.size()) {
        if(sum == k) {
            for(int &i : v) cout << i << " ";
            cout << "\n";
        }
        return;
    }

    v.push_back(vec[idx]);
    sum += vec[idx];

    subs_sum_k(idx+1,vec,v,sum,k);

    v.erase(v.begin() + v.size() - 1);
    sum -= vec[idx];

    subs_sum_k(idx+1,vec,v,sum,k);
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> empty(0);

    subs_sum_k(0,v,empty,0,k);
}