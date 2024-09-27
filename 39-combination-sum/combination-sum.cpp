class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, vector<int> &temp, vector<int>& candidates, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(n == 0) {
            return;
        }

        if(candidates[n - 1] <= target) {
            temp.push_back(candidates[n - 1]);
            solve(n, temp, candidates, target - candidates[n - 1]);
            temp.pop_back();
        }

        solve(n - 1, temp, candidates, target);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        solve(n, temp, candidates, target);
        return ans;
    }
};
