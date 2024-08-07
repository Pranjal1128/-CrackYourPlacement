class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = dp[1] = 1;
        int cnt2 = 1, cnt3 = 1, cnt5 = 1;
        for(int i = 2; i <= n; i++) {
            int temp = min(dp[cnt2]*2, min(dp[cnt3]*3, dp[cnt5]*5));
            if(temp == dp[cnt2]*2) cnt2++;
            if(temp == dp[cnt3]*3) cnt3++;
            if(temp == dp[cnt5]*5) cnt5++;
            dp[i] = temp;
        }
        return dp[n];
    }
};