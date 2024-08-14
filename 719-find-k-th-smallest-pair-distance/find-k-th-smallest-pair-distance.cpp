class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), mn = *min_element(nums.begin(), nums.end());
        vector<int> sz(mx - mn + 1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)  {
                sz[abs(nums[i] - nums[j])]++;
            }
        }

        for(int i = 0; i < sz.size(); i++) {
            k -= sz[i];
            if(k <= 0) return i;
        }

        return 0;
    }
};