#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

void print_all_subs(int idx,vector<int> vec, vector<int> v) {
    if(idx >= vec.size()) {
        for(int &i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    v.push_back(vec[idx]);
    print_all_subs(idx+1,vec,v);

    v.erase(v.begin() + v.size() - 1);
    print_all_subs(idx+1,vec,v);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> empty(0);

    print_all_subs(0,v,empty);
}