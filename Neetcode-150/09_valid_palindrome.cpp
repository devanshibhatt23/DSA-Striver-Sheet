#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(char c) {
        return ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')
        );
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
    
        while(l < r) {
            while(l<r && !valid(s[l])) {
                l++;
            }
            while(r>l && !valid(s[r])) {
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }

        return true;
    }
};