#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int totalFruits(vector<int>& fruits){
    int n = fruits.size();
    int ans = 0, count = 0;
    int left = 0, right = 0;

    unordered_map<int,int> m;

    while(right < n) {
        m[fruits[right]]++;

        while(m.size() > 2) {
            m[fruits[left]]--;
            if(m[fruits[left]] == 0) m.erase(fruits[left]);
            left++;
        }
        ans = max(ans,right-left+1);
        right++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    cout << totalFruits(nums);
}