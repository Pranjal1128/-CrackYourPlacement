class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int minIdx = -1;
            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }   
            }
            reverse(nums.begin() + pivot + 1, nums.end());
        }

        return;
    }
};