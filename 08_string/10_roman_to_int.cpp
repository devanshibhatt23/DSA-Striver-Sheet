#include <bits/stdc++.h>
#include <stack>
#define ll long long
using namespace std;

int romanToInt(string s) {
    int n = s.size();

    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for(int i=0; i<n; i++) {
        if(i != n-1) {
            int prev = m[s[i]], latter = m[s[i+1]];

            if(prev < latter) {
                ans += (latter - prev);
                i++;
            }
            else ans += prev;
        }
        else ans += m[s[i]];
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << romanToInt(s);
}