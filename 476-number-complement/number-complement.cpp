class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long long tws = 1;
        while(num) {
            int bit = num % 2 == 0 ? 1 : 0;
            ans += bit*tws;
            tws *= 2;
            num /= 2;
        }

        return ans;
    }
};