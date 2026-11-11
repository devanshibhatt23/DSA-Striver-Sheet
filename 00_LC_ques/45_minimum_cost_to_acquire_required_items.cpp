#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 <= costBoth) {
            return (cost1*1LL*need1) + (cost2*1LL*need2);
        }

        int both = min(need1, need2);

        long long total = both*1LL*costBoth;

        need1 -= both;
        need2 -= both;

        if(need1 > 0) {
            total += (need1 * 1LL * min(costBoth, cost1));
        }
        else if(need2 > 0) {
            total += (need2 * 1LL * min(costBoth, cost2));
        }

        return total;
    }
};