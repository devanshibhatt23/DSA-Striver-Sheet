#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

bool isIsomorphic(string s, string t) {
    map<char,char> m1;
    map<char,char> m2;

    for(int i=0; i<s.size(); i++) {
        if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else {
            if(s[i] != m2[t[i]] || t[i] != m1[s[i]]) return 0;
        }
    }

    return 1;
}

int main() {
    string a,b;
    char ch;
    cin >> a >> b;

    cout << isIsomorphic(a,b);
}