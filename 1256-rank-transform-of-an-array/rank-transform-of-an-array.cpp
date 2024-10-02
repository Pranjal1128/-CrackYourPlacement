class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<pair<int, pair<int, int>>> ans;
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back({arr[i], {i, -1}});
        }
        sort(ans.begin(), ans.end());
        ans[0].second.second = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(ans[i].first == ans[i - 1].first) ans[i].second.second = ans[i - 1].second.second;
            else ans[i].second.second = ans[i - 1].second.second + 1;
        }
        sort(ans.begin(), ans.end(), [&](auto a, auto b) {
            return a.second.first < b.second.first;
        });
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = ans[i].second.second;
        }

        return arr;
    }
};