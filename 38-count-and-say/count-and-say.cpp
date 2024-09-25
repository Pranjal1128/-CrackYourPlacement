class Solution {
public:
    string countAndSay(int n) {
        int j = 0, k = 0, cnt = 0;
        string prev = "1", temp = "";
        for(int i = 2; i <= n; i++) {
            j = 0, k = 0, temp = "";
            while(j < prev.size()) {
                cnt = 0;
                while(j < prev.size() && prev[j] == prev[k]) cnt++, j++;
                temp += to_string(cnt);
                temp += prev[k];
                k = j;
            }

            prev = temp;
        }

        return prev;
    }
};