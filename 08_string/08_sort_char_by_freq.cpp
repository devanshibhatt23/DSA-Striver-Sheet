#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

string frequencySort(string s) {
    map<char,int> freq;

    for(char &ch : s) freq[ch]++;  // O(n logk)

    sort(s.begin(), s.end(), [&](char a, char b) {  // O(n logn * logk)
        if(freq[a] == freq[b]) return a > b;
        return freq[a] > freq[b];
    });

    return s;
}

int main() {
    string s;
    cin >> s;

    cout << frequencySort(s);
}