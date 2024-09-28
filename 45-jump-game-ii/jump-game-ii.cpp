class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e4 + 1);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= nums.size()) break;
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
            }
        }

        return dp[nums.size() - 1];
    }
};