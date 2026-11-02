#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(target < matrix[0][0] || target > matrix[m-1][n-1]) {
            return 0;
        }

        int l=0, r=m-1;
        while(l < r) {
            int mid = (l+r)/2;

            if(target > matrix[mid][n-1]) {
                l = mid+1;
            }
            else if(target < matrix[mid][n-1]) {
                if(target < matrix[mid][0]) {
                    r = mid-1;
                }
                else {
                    l = mid;
                    break;
                }
            }
            else {
                return 1;
            }
        }

        int i = l;
        l = 0, r = n-1;

        while(l <= r) {
            int mid = (l+r)/2;

            if(target > matrix[i][mid]) {
                l = mid+1;
            }
            else if(target < matrix[i][mid]) {
                r = mid-1;
            }
            else {
                return 1;
            }
        }

        return 0;
    }
};