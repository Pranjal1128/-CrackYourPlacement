class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, int n, int m, bool &isIsland, vector<vector<int>> &vis, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis[i][j] = 1;
        if(!grid1[i][j]) isIsland = 0;

        for(auto d:dir) {
            int nx = i + d.first;
            int ny = j + d.second;
            if(nx < 0 || ny < 0  || nx >= n || ny >= m || !grid2[nx][ny] || vis[nx][ny]) continue;
            dfs(nx, ny, n, m, isIsland, vis, grid1, grid2);
        }

        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] && !vis[i][j]) {
                    bool isIsland = 1;
                    dfs(i, j, n, m, isIsland, vis, grid1, grid2);
                    cnt += isIsland;
                }
            }
        }

        return cnt;
    }
};