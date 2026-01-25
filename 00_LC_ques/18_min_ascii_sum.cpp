#include <bits/stdc++.h>
#define ll long long
#define f(i,s,e) for(int i=s; i<=e; i++)
#define en cout << "\n"
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    reverse(s1.begin(), s1.end());
}

int main() {
    cout << minimumDeleteSum("eat", "sea");
    en;
    cout << minimumDeleteSum("delete", "leet");
    en;
}