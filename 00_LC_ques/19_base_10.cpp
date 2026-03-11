#include <bits/stdc++.h>
#define ll long long
#define f(i,s,e) for(int i=s; i<=e; i++)
#define en cout << "\n"
using namespace std;

int bitwiseComplement(int n) {
    int ans = 0, leading_one = -1;
    
    for(int i=31; i>=0; i--) {
        if((n >> i) & 1) {
            leading_one = i;
            break;
        }
    }

    for(int i=leading_one; i>=0; i--) {
        if(((n >> i) & 1) == 0) {
            ans += (pow(2,i));
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << bitwiseComplement(n);
}