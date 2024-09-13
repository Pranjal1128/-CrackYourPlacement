class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> preXor(arr.size() + 1, 0);
        for(int i = 1; i <= arr.size(); i++) {
            preXor[i] = preXor[i - 1]^arr[i - 1];
        }

        vector<int> ans;
        for(auto i:queries) {
            int key = preXor[i[1] + 1]^preXor[i[0]];
            ans.push_back(key);
        }

        return ans;
    }
};