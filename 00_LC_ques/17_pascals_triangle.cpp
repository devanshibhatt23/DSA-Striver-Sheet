#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> solve(int numRows) {
    int n = numRows;
    vector<vector<int>> ans;

    for(int i=1; i<=n; i++) {
        vector<int> v(i);
        v[0] = 1, v[i-1] = 1;

        if(i > 2) {
            for(int j=1; j<i-1; j++) {
                v[j] = ans[i-2][j-1] + ans[i-2][j];
            }
        }
        ans.push_back(v);
    }

    return ans;
}

int main() {
    vector<vector<int>> v = solve(5);

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) cout << v[i][j] << " ";
        cout << endl;
    }
}