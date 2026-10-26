#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bruteForce(int n) {
        int ct_2 = 0, ct_5 = 0;

        for(int i=1; i<=n; i++) {
            if(i % 2 == 0) {
                int num = i;
                while(num % 2 == 0) {
                    num /= 2;
                    ct_2++;
                }
            }
            if(i % 5 == 0) {
                int num = i;
                while(num % 5 == 0) {
                    num /= 5;
                    ct_5++;
                }
            }
        }

        return min(ct_2,ct_5);
    }

    int opitmisedMethod(int n) {
        int ct = 0;
        int divisor = 5;

        while(n >= divisor) {
            ct += n/divisor;

            divisor *= 5;
        }

        return ct;
    }

    int trailingZeroes(int n) {
        return opitmisedMethod(n);
    }
};