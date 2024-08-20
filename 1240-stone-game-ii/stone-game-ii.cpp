class Solution {
public:
    int solve(int i, int m, vector<vector<int>>& dp, vector<int>& prefixSum) {
        int n = prefixSum.size() - 1;
        if (i >= n) return 0;
        if (dp[i][m] != -1) return dp[i][m];

        int maxStones = 0;
        for (int x = 1; x <= 2 * m; x++) {
            if (i + x > n) break;
            maxStones = max(maxStones, prefixSum[n] - prefixSum[i] - solve(i + x, max(m, x), dp, prefixSum));
        }

        dp[i][m] = maxStones;
        return maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 1, dp, prefixSum);
    }
};
