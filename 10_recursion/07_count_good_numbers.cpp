#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

int pow_func(long long x, long long n) {
    long long k = 1e9 + 7;
    long long ans = 1;

    while(n > 0) {
        if(n % 2 == 0) {
            x %= k;
            x *= x;
            x %= k;
            n /= 2;
        }
        else {
            ans = ans * x;
            ans %= k;
            n = n-1;
        }
    }

    return ans % k;
}

int countGoodNumbers(long long n) {
    long long k = 1e9 + 7;
    return (pow_func(5,(n+1)/2) * pow_func(4,n/2)) % k;
}