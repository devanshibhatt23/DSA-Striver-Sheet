#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void solve(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> s_row, s_col;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 0) {
                s_row.insert(i);
                s_col.insert(j);
            }
        }
    }

    for(int i : s_row) {
        for(int j=0; j<n; j++) matrix[i][j] = 0;
    }
    for(int i : s_col) {
        for(int j=0; j<m; j++) matrix[j][i] = 0;
    }

    for(int i=0; i<m; i++) {
        for(auto j : matrix[i]) cout << j << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> v = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    solve(v);
}