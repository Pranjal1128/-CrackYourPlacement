class Solution {
public:  
    long long subArrayRanges(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MIN;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            mx = nums[i];
            mn = nums[i];
            for(int j = i; j < n; j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                ans += (mx - mn);
            }
        }

        return ans;
    }
};  