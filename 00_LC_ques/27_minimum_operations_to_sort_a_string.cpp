#include <bits/stdc++.h>
using namespace std;

// TC - O(n), SC - O(1)
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(s.begin(), s.end())) return 0;
        else if(n == 2) return -1;

        char smallest = s[0], largest = s[0];
        for(char ch : s) {
            smallest = min(smallest,ch);
            largest = max(largest,ch);
        }

        if(smallest == s[0] || largest == s[n-1]) return 1;
        
        for(int i=1; i<n-1; i++) {
            if(s[i] == smallest || s[i] == largest) {
                return 2;
            }
        }

        return 3;
    }
};