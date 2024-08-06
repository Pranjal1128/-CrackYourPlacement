class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 1;
        dp[1] = 1;
        int no[3] = {2, 3, 5};
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                for(int k = 0; k < 3; k++) {
                    long long key = no[k]*dp[j];
                    if(key > dp[i - 1]) dp[i] = min(dp[i], key);
                }
            }
        }

        return (int)dp[n];
    }
};