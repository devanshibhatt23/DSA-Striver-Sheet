#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    int n = s.size();
    
    vector<vector<char>> v(numRows, vector<char> (n,' '));

    int k = 1, i = 0, j = 0;
    v[0][0] = s[0];

    if(numRows == 1) return s;

    while(k < n) {
        for(i=1; k<n && i<numRows; i++) {
            v[i][j] = s[k];
            k++;
        }

        i--;

        while(k<n && i>0) {
            i--;
            j++;
            v[i][j] = s[k];
            k++;
        }
    }

    string ans = "";

    for(auto vec : v) {
        for(auto ch : vec) {
            if(ch != ' ') ans.push_back(ch);
        }
    }

    return ans;
}

int main() {
    cout << convert("AB",1);
}