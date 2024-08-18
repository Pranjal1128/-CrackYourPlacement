class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt_2 = 1, cnt_3 = 1, cnt_5 = 1;
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; i++) {
            int temp = min(2*dp[cnt_2], min(3*dp[cnt_3], 5*dp[cnt_5]));
            if(temp == 2*dp[cnt_2]) cnt_2++;
            if(temp == 3*dp[cnt_3]) cnt_3++;
            if(temp == 5*dp[cnt_5]) cnt_5++;
            dp[i] = temp;
        }

        return dp[n];
    }
};