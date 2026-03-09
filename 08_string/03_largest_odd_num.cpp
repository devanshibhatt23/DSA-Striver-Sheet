#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

string largestOddNumber(string num) {
    string ans = "";
    int n = num.size();
    int last_idx = -1;

    for(int i=n-1; i>=0; i--) {
        if(int(num[i]) % 2) {
            last_idx = i;
            break;
        }
    }

    for(int i=0; i<=last_idx; i++) {
        ans.push_back(num[i]);
    }

    return ans;
}

int main() {
    string s;
    getline(cin,s);

    cout << largestOddNumber(s);
}