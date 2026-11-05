#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9+7;

        for(long long bit=n-1; bit>=0; bit--) {
            long long mask = (1LL << bit);

            if((a & mask) && (b & mask)) {
                continue;
            }
            else if(a & mask) {
                if(a > b) {
                    a ^= mask;
                    b ^= mask;
                }
            }
            else if(b & mask) {
                if(b > a) {
                    a ^= mask;
                    b ^= mask;
                }
            }
            else {
                a ^= mask;
                b ^= mask;
            }
        }

        return ((a%mod) * (b%mod) % mod);
    }
};