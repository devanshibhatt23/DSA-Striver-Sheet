#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// brute force - TC - O(n * n), SC - O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> mp;

        for(int i=0; i<9; i++) {
            mp.clear();

            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;

                if(mp.count(board[i][j])) {
                    return false;
                }
                mp[board[i][j]] = 1;
            }
        }

        for(int j=0; j<9; j++) {
            mp.clear();

            for(int i=0; i<9; i++) {
                if(board[i][j] == '.') continue;

                if(mp.count(board[i][j])) {
                    return false;
                }
                mp[board[i][j]] = 1;
            }
        }

        for(int x=0; x<3; x++) {
            for(int y=0; y<3; y++) {
                mp.clear();

                for(int i=3*x; i<3*x+3; i++) {
                    for(int j=3*y; j<3*y+3; j++) {
                        if(board[i][j] == '.') continue;

                        if(mp.count(board[i][j])) {
                            return false;
                        }
                        mp[board[i][j]] = 1;
                    }
                }
            }
        }

        return true;
    }
};

// TC - O(n * n), SC - O(n * n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>, unordered_set<char>> squares;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];

                if(ch == '.') continue;

                if(rows[i].count(ch) || cols[j].count(ch) || squares[{i/3, j/3}].count(ch)) return false;

                rows[i].insert(ch);
                cols[j].insert(ch);
                squares[{i/3, j/3}].insert(ch); 
            }
        }

        return true;
    }
};

// TC - O(n * n), SC - O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0), cols(9,0), squares(9,0);

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;

                int val = board[i][j] - '1';

                if((rows[i] & (1 << val)) || (cols[j] & (1 << val)) || squares[(i/3 * 3 + j/3)] & (1 << val)) {
                    return false;
                }

                rows[i] |= (1 << val);
                cols[j] |= (1 << val);
                squares[(i/3 * 3 + j/3)] |= (1 << val);
            }
        }

        return true;
    }
};