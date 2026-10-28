#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hashTable(string &s1, string &s2) {
        unordered_map<char,int> mp1;
        int m = s2.size();

        for(char ch : s1) mp1[ch]++;

        int n = mp1.size();

        for(int i=0; i<m; i++) {
            unordered_map<char,int> mp2;
            int curr = 0;
            
            for(int j=i; j<m; j++) {
                char ch = s2[j];
                mp2[ch]++;

                if(mp1[ch] < mp2[ch]) break;
                if(mp1[ch] == mp2[ch]) curr++;
                if(curr == n) return true;
            }
        }

        return false;
    }

    bool slidingWindow(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return 0;

        vector<int> mp1(26,0), mp2(26,0);
        for(char ch : s1) mp1[ch-'a']++;

        int l = 0, r = n-1;

        for(int i=l; i<=r; i++) {
            mp2[s2[i]-'a']++;
        }

        while(r < m-1) {
            if(mp1 == mp2) return 1;

            mp2[s2[l]-'a']--;
            mp2[s2[r+1]-'a']++;

            l++, r++;
        }

        if(mp1 == mp2) return 1;
        return 0;
    }

    bool checkInclusion(string s1, string s2) {
        // return hashTable(s1,s2);

        return slidingWindow(s1,s2);
    }
};