class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        vector<int> sufSum(n + 1, 0);
        preSum[0] = 0;
        sufSum[n] = 0;
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            sufSum[n - i] = sufSum[n - i + 1] + nums[n - i]; 
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = abs(preSum[i] - sufSum[i + 1]);
        }

        return ans;
    }
};