#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    int left = 0, right = 0;
    int length = INT_MAX, count = 0, idx = -1;

    unordered_map<char,int> mp;
    for(char &ch : t) mp[ch]++;

    while(right < m) {
        char ch = s[right];

        if(mp[ch] > 0) {
            count++;
        }
        mp[ch]--;
        
        while(count == n && left <= right) {
            if(right-left+1 < length) {
                length = right-left+1;
                idx = left;
            }

            mp[s[left]]++;

            if(mp[s[left]] > 0) {
                count--;
            }
            left++;
        }
        right++;
    }

    if(idx == -1) return "";
    return s.substr(idx,length);
}

int main() {
    string s,t;
    cin >> s >> t;

    cout << minWindow(s,t);
}