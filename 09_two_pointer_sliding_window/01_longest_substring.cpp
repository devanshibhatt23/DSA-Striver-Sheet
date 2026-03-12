#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    if(s.size()) ans = 1;
    
    int left = 0, right = 0;

    vector<int> hash(256,-1);

    while(right < n) {
        int x = s[right];

        if(hash[x] != -1) {
            if(hash[x] >= left) {
                left = hash[x] + 1;
            }
        }
        ans = max(ans, right-left+1);
        hash[x] = right;
        right++;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);
}