class Solution {
public:
    bool NoOfBouquetsOK(vector<int>& bloomDay, int m, int k, int d) {
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= d) {
                cnt++;
                if(cnt == k) {
                    m--;
                    cnt = 0;
                    if(m == 0) return true;
                }
            }
            else cnt = 0;
        }
        cout << d << " " << m << endl;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1, e = *max_element(bloomDay.begin(), bloomDay.end());
        if(bloomDay.size()/k < m) return -1;
        int ans = -1;
        while(s <= e) {
            int mid = (s + (e - s)/2);
            if(NoOfBouquetsOK(bloomDay, m, k, mid)) ans = mid, e = mid - 1;
            else s = mid + 1;
        }

        return ans;
    }
};
