#include <bits/stdc++.h>
#define ll long long
#define f(i,s,e) for(int i=s; i<=e; i++)
#define en << "\n"
using namespace std;

void solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    reverse(matrix.begin(), matrix.end());

    f(i,0,n-1) {
        f(j,i+1,n-1) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    f(i,0,n-1) {
        f(j,0,n-1) cout << matrix[i][j] << " ";
        cout en;
    }    
    cout en;
}

int main() {
    vector<vector<int>> v = {{0,1,2}, {3,4,5}, {1,3,1}};

    solve(v);
}