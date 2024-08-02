class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSumZ(n + 1, 0);
        vector<int> preSumO(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            preSumZ[i] = (nums[i - 1] == 0) + preSumZ[i - 1];
            preSumO[i] = (nums[i - 1] == 1) + preSumO[i - 1];
        }
    
        int i = 0, j = preSumZ[n] - 1, ans = INT_MAX, cnt;
        while(j < n) {
            cnt = preSumZ[n] - (preSumZ[j + 1] - preSumZ[i]);
            ans = min(ans, cnt);
            i++, j++;
        }
        i = 0, j = preSumO[n] - 1;
        while(j < n) {
            int cnt = preSumO[n] - (preSumO[j + 1] - preSumO[i]);
            ans = min(ans, cnt);
            i++, j++;
        }

        return ans;
    }
};