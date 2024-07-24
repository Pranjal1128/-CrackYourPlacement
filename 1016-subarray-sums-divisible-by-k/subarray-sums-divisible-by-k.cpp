class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int temp = (sum % k + k) % k;
            ans += mp[temp];
            mp[temp]++;
        }

        return ans;
    }
};