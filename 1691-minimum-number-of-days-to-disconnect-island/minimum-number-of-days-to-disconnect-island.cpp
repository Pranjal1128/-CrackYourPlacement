// class Solution {
// public:
//     vector<pair<int, int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &vis) {
//         vis[i][j] = 1;
//         for(auto d:dir) {
//             int nx = i + d.first;
//             int ny = j + d.second;
//             if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == 0) continue;
//             dfs(nx, ny, n, m, grid, vis);
//         }
//     }

//     int minDays(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int cnt = 0, ans = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(!vis[i][j] && grid[i][j] == 1) {
//                     cnt++;
//                     if(cnt > 1) return 0;
//                     dfs(i, j, n, m, grid, vis);
//                     if(i + 1 < n && grid[i + 1][j] == 1) ans++;
//                     if(j + 1 < m && grid[i][j + 1] == 1) ans++;
//                 } 
//             }
//         }

//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] == 1) {
//                     grid[i][j] = 0;
//                     if (minDays(grid) != 1) return 1;
//                     grid[i][j] = 1;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        auto count_islands = [&]() -> int {
            vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), 0));
            int islands = 0;
            
            function<void(int, int)> dfs = [&](int r, int c) {
                seen[r][c] = 1;
                for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !seen[nr][nc]) {
                        dfs(nr, nc);
                    }
                }
            };
            
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1 && !seen[i][j]) {
                        islands++;
                        dfs(i, j);
                    }
                }
            }
            return islands;
        };
        
        if (count_islands() != 1) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count_islands() != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};