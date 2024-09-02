class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int b) {
        long long n = chalk.size() , ans = -1, k = b;
        vector<long long> v(n + 1, 0);
        for(int i = 0; i < n; i++) {
            v[i + 1] = chalk[i] + v[i];
        }
        while(k >= v[n]) {
            k -= v[n];
        }
        for(int i = 0; i < n; i++) {
            if(v[i + 1] > k) {
                ans = i;
                break;
            }
        }
        return (int)ans;
    }
};