class Solution {
public:
    string stringHash(string s, int k) {
        int i = 0, j = k - 1;
        string ans = "";
        while(j < s.size()) {
            int temp = 0;
            for(int x = i; x <= j; x++) {
                temp += (s[x] - 'a');
            }
            ans += ('a' + temp%26);
            i = j + 1;
            j += k;
        }

        return ans;
    }
};