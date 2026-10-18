#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// TC - O(m * n log n), SC - O(m * n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s : strs) {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// TC - O(m * n), SC - O(m * n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(string s : strs) {
            vector<int> count(26,0);

            for(char ch : s) {
                count[ch-'a']++;
            }

            string str;
            for(int i : count) str.push_back(i);

            mp[str].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};