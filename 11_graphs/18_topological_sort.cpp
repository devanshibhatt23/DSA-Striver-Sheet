/* topological sort 
- only in directed acyclic graph
- if there is an edge from u to v in the graph (u -> v), then u appears before v in the sorted arr
*/

#include <bits/stdc++.h>
#include <stack>
using namespace std;

vector<vector<int>> adjacency_list(int n, int m) {
    vector<vector<int>> arr(n+1, vector<int> (0));

    while(m--) {
        int x,y;
        cin >> x >> y;

        arr[x].push_back(y);
    }

    return arr;
}

void dfs(int start, vector<vector<int>> &adj_list, vector<int> &visited, stack<int> &st) {
    visited[start] = 1;

    for(int node : adj_list[start]) {
        if(!visited[node]) dfs(node,adj_list,visited,st);
    }

    st.push(start);
}

vector<int> topologicalSort(vector<vector<int>> &adj_list) {
    int n = adj_list.size()-1;

    vector<int> visited(n+1,0);
    vector<int> sorted;
    stack<int> st;

    for(int i=1; i<=n; i++) {
        if(!visited[i]) dfs(i,adj_list,visited,st);
    }

    while(!st.empty()) {
        sorted.push_back(st.top());
        st.pop();
    }

    return sorted;
}