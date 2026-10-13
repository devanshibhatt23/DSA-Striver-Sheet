#include <bits/stdc++.h>
using namespace std;

class Solution {
    char get_char(int n) {
        if(n == 1) return 'I';
        if(n == 5) return 'V';
        if(n == 10) return 'X';
        if(n == 50) return 'L';
        if(n == 100) return 'C';
        if(n == 500) return 'D';
        return 'M';
    }

public:
    string intToRoman(int num) {
        string ans = "";
        int n = 1;
        int x = num;

        while(x) {
            n++;
            x /= 10;
        }

        while(n--) {
            int power = pow(10,n-1);
            int digit;

            if(power == 0) {
                digit = num % 10;
            }
            else digit = num / power;

            if(digit <= 3) {
                char symbol = get_char(power);

                for(int i=0; i<digit; i++) ans.push_back(symbol);
            }
            else if(digit == 4) {
                ans.push_back(get_char(power));
                ans.push_back(get_char(5 * power));
            }
            else if(digit == 5) {
                ans.push_back(get_char(5 * power));
            }
            else if(digit <= 8) {
                int a = digit-5;
                char ch = get_char(power);

                ans.push_back(get_char(5 * power));

                for(int i=0; i<a; i++) {
                    ans.push_back(ch);
                }
            }
            else if(digit == 9) {
                ans.push_back(get_char(power));
                ans.push_back(get_char(10 * power));
            }
            else {
                ans.push_back(get_char(power));
            }

            num -= (digit * power);
        }

        return ans;
    }
};