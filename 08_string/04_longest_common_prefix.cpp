#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string common_pref = "";
    int min_length = INT_MAX;

    for (int i=0; i<strs.size(); i++) {
        int n = strs[i].size();
        min_length = min(min_length, n);
    }

    for (int i = 0; i < min_length; i++) {
        bool check = 1;
        for (int j = 0; j < strs.size() - 1; j++) {
            if (strs[j][i] != strs[j + 1][i]) {
                check = 0;
                return common_pref;
            }
        }

        if (check) {
            common_pref.push_back(strs[0][i]);
        }
    }

    return common_pref;
}

int main() {
    vector<string> strs(3);
    for(int i=0; i<3; i++) {
        cin >> strs[i];
        char ch;
        cin >> ch;
    }

    cout << longestCommonPrefix(strs);
}