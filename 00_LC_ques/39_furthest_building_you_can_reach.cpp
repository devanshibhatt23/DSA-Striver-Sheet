#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int b = 0;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<n-1; i++) {
            int diff2 = heights[i+1] - heights[i];

            if(heights[i+1] > heights[i]) {
                if(b > bricks) {
                    return i;
                }

                if(minHeap.size() == ladders) {
                    if(minHeap.empty()) {
                        b += diff2;
                        if(b > bricks) {
                            return i;
                        }
                        continue;
                    }

                    int diff1 = minHeap.top();
                    
                    if(diff1 < diff2) {
                        minHeap.pop();
                        minHeap.push(diff2);
                        
                        b += diff1;
                        if(b > bricks) {
                            return i;
                        }
                    }
                    else {
                        b += diff2;
                        if(b > bricks) {
                            return i;
                        }
                    }
                }
                else {
                    minHeap.push(heights[i+1] - heights[i]);
                }
            }
        }

        if(b > bricks) {
            return n-2;
        }

        return n-1;
    }
};