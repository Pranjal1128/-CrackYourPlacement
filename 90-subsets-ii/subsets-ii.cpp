class Solution {
public:
    set<vector<int>> s;
    void solve(int idx, vector<int>& nums, vector<int> &temp) {
        if(idx == nums.size()) {
            s.insert(temp);
            return;
        } 

        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);
        temp.pop_back();
        solve(idx + 1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp);
        for(auto v:s) {
            res.push_back(v);
        }
        return res;
    }
};
