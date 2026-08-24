#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for(int i=0; i<n/2; i++) {
            if(num[i] != '?') {
                sum1 += (num[i] - '0');
            }
            else q1++;
        }

        for(int i=n/2; i<n; i++) {
            if(num[i] != '?') {
                sum2 += (num[i] - '0');
            }
            else q2++;
        }

        int q = q1 + q2;

        if(q%2 == 1 || 2*(sum1-sum2) != (9 * (q2-q1))) return 1;

        return 0;
    }
};