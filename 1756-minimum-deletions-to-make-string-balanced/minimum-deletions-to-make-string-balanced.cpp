class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> preA(n + 1, 0);
        vector<int> preB(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            preA[i] = (s[i - 1] == 'a') + preA[i - 1];
            preB[i] = (s[i - 1] == 'b') + preB[i - 1];
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            ans = min(ans, preB[i - 1] + preA[n] - preA[i]);
        }
        return ans;
    }
};