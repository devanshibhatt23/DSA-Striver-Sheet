#include <bits/stdc++.h>
#include <stack>
#define ll long long
using namespace std;

int myAtoi(string s) {
    int n = s.size();
    if(n == 0) return 0;
    
    int i=0, sign = 1;
    long long ans = 0;

    while(i < n && s[i] == ' ') i++;
    
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        if(s[i] == '-') sign = -1;
        i++;
    }

    if(isdigit(s[i]) == 0 || i>n-1) return 0; 

    while(i < n && isdigit(s[i])) {
        ans = ans*10 + (s[i] - '0');
        i++;

        if(sign * ans >= INT_MAX) return INT_MAX;
        if(sign * ans <= INT_MIN) return INT_MIN;
    }

    return sign * ans;
}

int main() {
    string s;
    cin >> s;

    cout << myAtoi(s);
}