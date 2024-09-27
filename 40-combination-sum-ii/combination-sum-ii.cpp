class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> &temp, vector<int>& candidates, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i + 1, temp, candidates, target - candidates[i]);
            temp.pop_back();
        }
        
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, temp, candidates, target);
        return ans;
    }
};
