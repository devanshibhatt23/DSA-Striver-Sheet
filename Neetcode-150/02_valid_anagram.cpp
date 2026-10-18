#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> mp;

        for(int i=0; i<s.size(); i++) mp[s[i]]++;

        for(char ch : t) {
            if(!mp.count(ch) || mp[ch] <= 0) return false;
            mp[ch]--;
        }

        for(auto it : mp) {
            if(it.second > 0) return false;
        }

        return true;
    }
};