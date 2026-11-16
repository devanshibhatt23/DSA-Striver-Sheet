#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        string str = s;

        while(str.size() > k) {
            int n = str.size();

            string new_str = "";
            int sum = 0;
            int ct = 0;

            for(int i=0; i<n; i++) {
                if(ct == k) {
                    new_str.append(to_string(sum));

                    ct = 0;
                    sum = 0;
                }

                sum += (str[i]-'0');
                ct++;

                if(i == n-1 && ct <= k) {
                    new_str.append(to_string(sum));
                }
            }

            str = new_str;
            cout << str << " ";
        }

        return str;     
    }
};