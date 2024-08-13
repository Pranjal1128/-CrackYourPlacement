class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int> &temp, vector<int>& c, int t) {
        if(t == 0) {
            ans.push_back(temp);
            return;
        }
        if(i == c.size()) return;
        if(c[i] <= t) {
            temp.push_back(c[i]);
            solve(i + 1, temp, c, t - c[i]);
            temp.pop_back();
        }
        while (i + 1 < c.size() && c[i] == c[i + 1]) {
            i++;
        }
        solve(i + 1, temp, c, t);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n = c.size();
        sort(c.begin(), c.end());
        vector<int> temp;
        ans.clear();
        solve(0, temp, c, target);
        return ans;
    }
};