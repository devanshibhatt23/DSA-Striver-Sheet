#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nth_root(int n, int m) {
    int low = 1, high = m;

    while(low <= high) {
        int mid = (low + high) / 2;

        int prod = 1;
        for(int i=0; i<n; i++) prod *= mid;

        if(prod == m) return mid;
        else if(prod < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    cout << nth_root(3,26);
}