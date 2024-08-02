class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            leftSum += nums[i];
            ans[i] = abs(rightSum - leftSum);
            rightSum -= nums[i]; 
        }

        return ans;
    }
};