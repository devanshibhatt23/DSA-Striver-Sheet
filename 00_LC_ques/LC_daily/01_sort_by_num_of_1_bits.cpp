#include <bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    map<int,vector<int>> m;

    for(int &i : arr) {
        int ct_one_bits = 0, val = i;
        while(val) {
            val = val & (val-1);
            ct_one_bits++;
        }
        
        m[ct_one_bits].push_back(i);
    }

    int k = 0;
    for(auto &i : m) {
        sort((i.second).begin(), (i.second).end());
        for(int &j : (i.second)) {
            arr[k] = j;
            k++;
        }
    }

    return arr;
}

static int popcount(int a) {
    int ct = 0;
    while(a) {
        a = a & (a-1);
        ct++;
    }
    return ct;
}

static bool compare(int a, int b) {
    int ct_a = popcount(a), ct_b = popcount(b);
    if(ct_a == ct_b) return a < b;
    else return ct_a < ct_b;
}

vector<int> sortByBits2(vector<int>& arr) {
    sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> sorted(n);
    sorted = sortByBits2(arr);

    for(int &i : sorted) cout << i << " ";
}