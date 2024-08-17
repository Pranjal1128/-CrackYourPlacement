class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int s = 1, e = k, t = 0;
        vector<int> ans;
        for(int i = 0; i < k - 1; i++) {
            if(nums[i + 1] == nums[i] + 1) t++;
        }
        if(t == k - 1) ans.push_back(nums[k - 1]);
        else ans.push_back(-1);
        while(e < nums.size()) {
            if(nums[e] == nums[e - 1] + 1) t++;
            if(nums[s] == nums[s - 1] + 1) t--;

            if(t == k - 1) {
                ans.push_back(nums[e]);
            }
            else {
                ans.push_back(-1);
            }
            s++, e++;
        }

        return ans;
    }
};