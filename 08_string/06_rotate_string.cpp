#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

bool rotateString(string s, string goal) {
    int n = s.size();
    if(n != goal.size()) return 0;

    for(int k=1; k<=n; k++) {
        bool is_k_valid = 1;

        for(int i=0; i<n; i++) {
            if(s[i] != goal[(i+k)%n]) {
                is_k_valid = 0;
                break;
            }
        }

        if(is_k_valid) return 1;
    }

    return 0;
}

int main() {
    string a,b;
    char ch;
    cin >> a >> b;

    cout << rotateString(a,b);
}