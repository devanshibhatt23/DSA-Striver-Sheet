#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    if(s.size() == 0) return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0, cookie = 0;
    int count = 0;

    while(child < g.size() && cookie < s.size()) {
        if(g[child] <= s[cookie]) {
            count++;
            child++;
        }
        cookie++;
    }

    return count;
}

int main() {
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << findContentChildren(g,s);
}