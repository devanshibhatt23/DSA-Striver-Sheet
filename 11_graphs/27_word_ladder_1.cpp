#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
using namespace std;

int bfs(string beginWord, string endWord, vector<string> &wordList) {
    queue<pair<string,int>> q;
    unordered_map<string,int> mp;
    unordered_set<string> st;

    for(auto &str : wordList) st.insert(str);

    if(st.count(endWord) == 0) return 0;

    q.push({beginWord,1});

    while(!q.empty()) {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        if(word == endWord) return level;
        mp[word] = 1;

        string original_word = word;

        for(int i=0; i<word.size(); i++) {
            for(char letter='a'; letter<='z'; letter++) {
                word[i] = letter;
    
                if(st.find(word) != st.end() && mp.find(word) == mp.end()) {
                    q.push({word,level+1});
                    mp[word] = 1;
                }
            }

            word = original_word;
        }
    }

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    return bfs(beginWord,endWord,wordList);
}