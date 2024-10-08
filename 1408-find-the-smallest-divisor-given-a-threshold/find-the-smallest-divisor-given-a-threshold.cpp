class Solution {
public:
    bool isValid(int m, vector<int>& nums, int threshold) {
        int sum = 0;
        for(auto i : nums) {
            sum += ceil(i/(m*1.0));
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(s <= e) {
            int m = (s + (e - s)/2);
            if(isValid(m, nums, threshold)) {
                ans = m;
                e = m - 1;
            }
            else s = m + 1;
        }

        return ans;
    }
};