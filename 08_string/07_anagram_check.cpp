#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return 0;

    unordered_map<char,int> count_in_s, count_in_t;

    for(char &ch : s) count_in_s[ch]++;
    for(char &ch : t) count_in_t[ch]++;

    for(auto &it : count_in_s) {
        if(it.second != count_in_t[it.first]) return 0;
    }

    return 1;
}

int main() {
    string a,b;
    char ch;
    cin >> a >> b;

    cout << isAnagram(a,b);
}