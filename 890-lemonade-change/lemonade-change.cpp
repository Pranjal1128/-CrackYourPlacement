class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5 = 0, cnt_10 = 0, cnt_20 = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) cnt_5++;

            else if(bills[i] == 10) {
                cnt_10++;
                if(cnt_5 == 0) return false;
                cnt_5--; 
            } 

            else {
                if(cnt_10 == 0) {
                    if(cnt_5 < 3) return false;
                    cnt_5 -= 3;
                }
                else {
                    cnt_10--;
                    if(cnt_5 == 0) return false;
                    cnt_5--;
                }
            }
        }

        return true;
    }
};