class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string ans = "";
        while(num1 != 0 || num2 != 0 || num3 != 0) {
            int d = min(num1%10, min(num2%10, num3%10));
            ans += to_string(d);
            num1 = num1/10;
            num2 = num2/10;
            num3 = num3/10;
        }
        reverse(ans.begin(), ans.end());
        int res = stoi(ans);
        return res;
    }
};