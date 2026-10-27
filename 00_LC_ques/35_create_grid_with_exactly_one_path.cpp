#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == m-1) grid[i].push_back('.');
                else if(j == 0) grid[i].push_back('.');
                else grid[i].push_back('#');
            }
        }

        return grid;
    }
};