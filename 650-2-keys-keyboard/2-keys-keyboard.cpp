class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = dp[1] = 0;
        int temp = 0; 
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                if((i - j) % j == 0) dp[i] = min(dp[i], dp[j] + (i - j)/j + 1);
            }
        }

        return dp[n];
    }
};