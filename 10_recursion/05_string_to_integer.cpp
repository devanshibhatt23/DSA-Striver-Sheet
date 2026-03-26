#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

int func(string s, int i, long long &result, int &sign) {
    if(i > s.size()-1 || isdigit(s[i]) == 0) return result*sign;

    result = result*10 + (s[i] - '0');
    
    if(sign*result >= INT_MAX) {
        result = INT_MAX;
        return result;
    }
    if(sign*result <= INT_MIN) {
        result = INT_MIN;
        return result;
    }

    return func(s,i+1,result,sign);
}

int myAtoi(string s) {
    int n = s.size(), i = 0;
    long long ans = 0;
    int sign = 1;

    while(i < n && s[i] == ' ') i++;

    if(i < n && (s[i] == '+' || s[i] == '-')) {
        if(s[i] == '+') sign = 1;
        else sign = -1;
        i++;
    }

    func(s,i,ans,sign);

    return ans*sign;
}