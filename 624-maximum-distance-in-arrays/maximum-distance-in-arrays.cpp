class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        pair<int, int> mx = {INT_MIN, -1}, mn = {INT_MAX, -1};
        for(int i = 0; i < a.size(); i++) {
            int n = a[i].size();
            if(mx.first < a[i][n - 1]) {
                mx.first = a[i][n - 1];
                mx.second = i;
            }
            if(mn.first > a[i][0]) {
                mn.first = a[i][0];
                mn.second = i;
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < a.size(); i++) {
            int n = a[i].size();
            if(i != mx.second) ans = max(ans, mx.first - a[i][0]);
            if(i != mn.second) ans = max(ans, a[i][n - 1] - mn.first);
        }

        return ans;
    }
};