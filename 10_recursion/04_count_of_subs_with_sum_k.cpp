#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

int subs_sum_k(int idx, vector<int> vec, vector<int> v, int sum, int k) {
    if(idx >= vec.size()) {
        if(sum == k) {
            return 1;
        }
        return 0;
    }

    v.push_back(vec[idx]);
    sum += vec[idx];

    int taking = subs_sum_k(idx+1,vec,v,sum,k);

    v.erase(v.begin() + v.size() - 1);
    sum -= vec[idx];

    int not_taking = subs_sum_k(idx+1,vec,v,sum,k);

    return taking + not_taking;
}

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> empty(0);

    cout << subs_sum_k(0,v,empty,0,k);
}