#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int total_computers = 0, isolated_computers = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    total_computers++;

                    bool found = 0;

                    for(int k=0; k<m; k++) {
                        if(grid[k][j] && k != i) {
                            found = 1;
                            break;
                        }
                    }

                    for(int k=0; k<n; k++) {
                        if(grid[i][k] && k != j) {
                            found = 1;
                            break;
                        }
                    }

                    if(!found) {
                        isolated_computers++;
                    }
                }
            }
        }

        return total_computers - isolated_computers;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int total_computers = 0, isolated_computers = 0;

        unordered_map<int,int> rows;
        unordered_map<int,int> cols;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    total_computers++;
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    if(rows[i] > 1 || cols[j] > 1) {
                        continue;
                    }
                    else {
                        isolated_computers++;
                    }
                }
            }
        }

        return total_computers - isolated_computers;
    }
};