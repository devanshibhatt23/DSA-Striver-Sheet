#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    int count = 0;
    int left = 0, right = 0;

    vector<int> v(3,0);

    while(right < n) {
        v[s[right] - 'a']++;

        while(s[0] > 0 && s[1] > 0 && s[2] > 0) {
            count += (n - right + left);
            v[s[left] - 'a']--;
            left++;
        }

        right++;
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << numberOfSubstrings(s);
}