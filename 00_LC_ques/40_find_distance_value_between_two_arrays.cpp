#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();
        int ans = 0;

        sort(arr2.begin(), arr2.end());

        for(int i=0; i<n; i++) {
            int val = arr1[i];

            int l = 0, r = m-1;
            int smallest = 1e9, largest = 1e9;
            while(l <= r) {
                int mid = (l+r)/2;

                if(arr2[mid] <= val) {
                    smallest = arr2[mid];
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }

            l = 0, r = m-1;
            while(l <= r) {
                int mid = (l+r)/2;

                if(arr2[mid] > val) {
                    largest = arr2[mid];
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }

            int diff1 = abs(smallest-val);
            int diff2 = abs(largest-val);

            if(min(diff1,diff2) > d) ans++;
        }

        return ans;
    }
};