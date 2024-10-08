class Solution {
public:
    bool canBeShipped(int minWeight, vector<int>& w, int d) {
        int cnt = 0, sum = 0;
        for(auto i:w) {
            sum += i;
            if(i > minWeight) return false;
            if(sum > minWeight) {
                cnt++;
                sum = i;
            }
        }
        if(sum <= minWeight) cnt++;
        return cnt <= d;
    }

    int shipWithinDays(vector<int>& w, int d) {
        int s = 1, e = accumulate(w.begin(), w.end(), 0);
        int ans = -1;
        while(s <= e) {
            int m = s + (e - s)/2;
            if(canBeShipped(m, w, d)) {
                ans = m;
                e = m - 1;
            }
            else s = m + 1;
        }

        return ans;
    }
};