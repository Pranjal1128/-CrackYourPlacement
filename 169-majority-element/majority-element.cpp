class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == ans) {
                cnt++;
                ans = nums[i];
            } 
            else {
                if(cnt == 0) {
                    cnt = 1;
                    ans = nums[i];
                }
                else cnt--;
            }
        }

        return ans;
    }
};