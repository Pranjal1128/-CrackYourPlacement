class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        while(i < n && j < n) {
            if(nums[i] != 0) i++, j = i;
            else if(nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j = i;
            } 
            else j++;
        }
        return;
    }
};