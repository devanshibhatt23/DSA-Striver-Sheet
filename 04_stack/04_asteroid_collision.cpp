#include <bits/stdc++.h>
#include <stack>
#define ll long long
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for(auto &x : asteroids) {
        if(x >= 0) st.push(x);
        else {
            while(!st.empty() && st.top() >= 0 && st.top() < -1*x) {
                st.pop();
            }
            if(!st.empty() && st.top() == -1*x) st.pop();
            else if(st.empty() || st.top() < 0) st.push(x);
        }
    }

    vector<int> final_asteroids;
    while(!st.empty()) {
        final_asteroids.push_back(st.top());
        st.pop();
    }

    reverse(final_asteroids.begin(), final_asteroids.end());
    return final_asteroids;
}

int main() {
    vector<int> as = {3,5,-6,2,-1,4};
    vector<int> final = asteroidCollision(as);

    for(auto i : final) cout << i << " ";
}