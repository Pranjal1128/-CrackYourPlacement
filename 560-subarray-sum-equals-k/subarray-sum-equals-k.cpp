class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0, j = 0;
        mp[0] = 1;
        while(j < nums.size()) {
            sum += nums[j++];
            cnt += mp[sum - k];
            mp[sum]++;
        }

        return cnt;
    }
};