#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void bfs(int row, int col, int color, int c, vector<vector<int>> &image) {
    int n = image.size(), m = image[0].size();

    queue<pair<int,int>> q;
    q.push({row,col});
    image[row][col] = color;

    while(!q.empty()) {
        pair<int,int> node = q.front();
        q.pop();

        int i = node.first, j = node.second;

        for(int diff=-1; diff<=1; diff++) {
            for(int diff2=-1; diff2<=1; diff2++) {
                if(diff*diff2) continue;

                int x = i + diff;
                int y = j + diff2;

                if(x >= 0 && x < n && y >= 0 && y < m && image[x][y] == c) {
                    q.push({x,y});
                    image[x][y] = color;
                }
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    int pixel_color = image[sr][sc];
    int n = image.size(), m = image[0].size();

    if(pixel_color == color) return image;

    bfs(sr,sc,color,pixel_color,image);

    return image;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> image[i][j];
        }
    }

    int sr,sc,color;
    cin >> sr >> sc >> color;

    for(auto i : floodFill(image,sr,sc,color)) {
        for(int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}