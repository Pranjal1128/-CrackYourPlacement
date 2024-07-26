class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        for(auto i:edges) {
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        int ans, mcnt = n;
        for(int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= dt && i != j) cnt++;
            }
            if(mcnt > cnt) {
                mcnt = cnt;
                ans = i;
            }
        }

        return ans;
    }
};