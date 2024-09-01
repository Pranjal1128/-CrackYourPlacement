class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m);
        if(original.size() != m*n) return {};
        int k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = k; j < k + n; j++) {
                ans[i].push_back(original[j]);
            }
            k += n;
        }

        return ans;
    }
};