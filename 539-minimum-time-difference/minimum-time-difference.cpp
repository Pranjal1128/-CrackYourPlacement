class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> secds;

        for (auto time : timePoints) {
            int hh = stoi(time.substr(0, 2)) * 60;
            int mm = stoi(time.substr(3, 2));     
            secds.push_back(hh + mm);
        }

        sort(secds.begin(), secds.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            ans = min(secds[i] - secds[i - 1], ans);
        }

        ans = min(ans, secds[0] + 1440 - secds[n - 1]);

        return ans;
    }
};
