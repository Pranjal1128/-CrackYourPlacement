class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int s = 0, e = k - 1;
        vector<int> ans;
        while(e < nums.size()) {
            int flag = 0;
            for(int i = s; i < e; i++) {
                if(nums[i + 1] != nums[i] + 1) {
                    ans.push_back(-1);
                    flag = 1;
                    break;
                }
            }

            if(!flag) ans.push_back(nums[e]);
            s++, e++;
        }

        return ans;
    }
};