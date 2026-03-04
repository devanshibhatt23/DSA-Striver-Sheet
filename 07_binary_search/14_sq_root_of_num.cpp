#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sq_root(int n) {
    int low = 1, high = n;
    int ans = 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid * mid <= n) {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    return ans;
}

int main() {
    cout << sq_root(1);
    // 1 2 3 4 5 6 7 ..
}