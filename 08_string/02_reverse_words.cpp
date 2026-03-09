#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

string reverseWords(string s) {
    int n = s.size();

    for(int i=0; i<n/2; i++) {
        swap(s[i], s[n-1-i]);
    }
    s += '_';

    int word_length = 0, len_of_last_word = 0;
    int last_idx = 0;

    for(int i=0; i<n && s[i] != '_'; i++) {
        if(s[i] != ' ') {
            word_length++;
            last_idx = i;
        }
        else {
            len_of_last_word = word_length;
            if(word_length) {
                reverse(s.begin()+i-word_length, s.begin()+i);
                word_length = 0;
            }
            else {
                s.erase(s.begin()+i);
                i--;
            }
        }
    }
    if(word_length) {
        len_of_last_word = word_length;
        int i = last_idx;
        reverse(s.begin()+i+1-len_of_last_word, s.begin()+i+1);
    }

    s.erase(s.end()-1);
    if(*(s.end()-1) == ' ') s.erase(s.end()-1);
    return s;
}

int main() {
    string s;
    getline(cin,s);

    cout << reverseWords(s) << " end";
}