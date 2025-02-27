class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;

        while(i < nums.size()) {
            if(nums[i] == nums[i - 1]) {
                i++;
            }
            else {
                nums[j++] = nums[i++];
            }
        }

        return j;
    }
};