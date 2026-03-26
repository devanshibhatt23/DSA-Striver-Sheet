#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

double positive_power(double x, long long n) {
    double ans = 1;

    while(n > 0) {
        if(n%2 == 0) {
            x *= x;
            n /= 2;
        }
        else {
            ans = ans * x;
            n = n-1;
        }
    }

    return ans;
}

double myPow(double x, int n) {
    long long k = n;

    if(n == 0) return 1;
    if(n > 0) return positive_power(x,k);
    return 1 / positive_power(x,-1*k);
}