#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

class Solution {
public:
    bool check(int idx, int i, int j, string &word, vector<vector<char>> &board) {
        if(idx >= word.size()) return 1;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || 
        word[idx] != board[i][j]) return 0;

        char temp = board[i][j];
        board[i][j] = '_';

        bool found = (check(idx+1,i+1,j,word,board) || 
        check(idx+1,i-1,j,word,board) || check(idx+1,i,j+1,word,board) || 
        check(idx+1,i,j-1,word,board));

        board[i][j] = temp;

        if(found) return 1;
        return 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(check(0, i,j,word,board)) return 1;
            }
        }

        return 0;
    }
};