#include <bits/stdc++.h>
#include <queue>
using namespace std;

string kahns_algorithm(vector<vector<int>> &adj_list) {
    int n = adj_list.size();

    vector<int> in_degree(n,0);
    queue<int> q;
    string sorted = "";

    for(int i=0; i<n; i++) {
        for(int node : adj_list[i]) {
            in_degree[node]++;
        }
    }

    for(int i=0; i<n; i++) {
        if(in_degree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();
        sorted.push_back(char('a' + i));

        for(int node : adj_list[i]) {
            in_degree[node]--;

            if(in_degree[node] == 0) q.push(node);
        }
    }

    return sorted;
}

string findOrder(vector<string> &dict, int n, int k) {
    vector<vector<int>> adj_list(k);

	for(int x=0; x<n-1; x++) {
        string first = dict[x];
        string second = dict[x+1];

        bool check = 0;

        for(int i=0,j=0; i<first.size() && j<second.size(); i++, j++) {
            if(first[i] != second[j]) {
                int x = first[i]-'a';
                int y = second[j]-'a';

                adj_list[x].push_back(y);
                check = 1;
                break;
            }
        }

        if(!check && second.size() < first.size()) {
            return "";
        }
    }

    string ans = kahns_algorithm(adj_list);
    if(ans.size() == k) return ans;
    return "";
}