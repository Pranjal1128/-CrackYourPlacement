class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> preSum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        vector<int> subSum;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int temp = preSum[j] - preSum[i];
                subSum.push_back(temp);
            }
        }

        sort(subSum.begin(), subSum.end());
        long long ans = 0;
        for(int i = left - 1; i < right; i++) {
            ans = ((ans + subSum[i]) % 1000000007);
        }
        return ans;
    }
};