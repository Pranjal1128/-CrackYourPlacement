class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int b) {
        int n = chalk.size(), k = b, ans = -1;
        long long key = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % key;
        for(int i = 0; i < n; i++) {
            if(k < chalk[i]) {
                ans = i;
                break;
            }
            k -= chalk[i];
        }
        return (int)ans;
    }
};