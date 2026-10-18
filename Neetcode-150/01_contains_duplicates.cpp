#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int i : nums) {
            if(st.count(i)) return true;
            st.insert(i);
        }

        return false;
    }
};