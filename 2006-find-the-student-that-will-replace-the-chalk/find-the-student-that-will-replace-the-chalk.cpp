class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int b) {
        long long n = chalk.size(), key = accumulate(chalk.begin(), chalk.end(), 0LL), k = b, ans = -1;
        k = k % key;
        key = 0;
        for(int i = 0; i < n; i++) {
            key += chalk[i];
            if(key > k) {
                ans = i;
                break;
            }
        }
        return (int)ans;
    }
};