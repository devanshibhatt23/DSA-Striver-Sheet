#include <bits/stdc++.h>
#include <queue>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector<vector<int>> dis_matrix(n, vector<int> (n,1e7));

    for(int i=0; i<n; i++) dis_matrix[i][i] = 0;

    for(auto &vec : edges) {
        dis_matrix[vec[0]][vec[1]] = vec[2];
        dis_matrix[vec[1]][vec[0]] = vec[2];
    }

    for(int via=0; via<n; via++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int total_dis = dis_matrix[i][via] + dis_matrix[via][j];
                if(dis_matrix[i][j] > total_dis) {
                    dis_matrix[i][j] = total_dis;
                }
            }
        }
    }

    int city_with_min_neigh = -1;
    int neighbours = INT_MAX;

    for(int i=0; i<n; i++) {
        int ct_dis_less_than_threshold = 0;

        for(int j=0; j<n; j++) {
            if(dis_matrix[i][j] <= distanceThreshold) ct_dis_less_than_threshold++;
        }

        if(ct_dis_less_than_threshold <= neighbours) {
            city_with_min_neigh = i;
            neighbours = ct_dis_less_than_threshold;
        }
    }

    return city_with_min_neigh;
}