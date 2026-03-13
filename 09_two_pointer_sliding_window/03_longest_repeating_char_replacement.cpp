#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int ans = 0, max_letter_count = 0;
    int left = 0, right = 0;
    vector<int> hash(26,0);

    // TC - O(n)
    // SC - O(26) = O(1)

    while(right < n) {
        char ch = s[right];
        hash[ch - 'A']++;

        max_letter_count = max(max_letter_count, hash[ch-'A']);
        int length = right-left+1;
        
        while(length - max_letter_count > k) {
            hash[(s[left] - 'A')]--;
            left++;
            length = right-left+1;
        }

        ans = max(ans,length);
        right++;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << characterReplacement(s,k);
}