class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, int k, int n, int m, vector<vector<char>>& board, string &word) {
        char temp = board[i][j];
        board[i][j] = '#';
        if(k == word.size()) return true;
        for(auto d:dir) {
            int nx = i + d.first;
            int ny = j + d.second;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != word[k]) continue;
            if(dfs(nx, ny, k + 1, n, m, board, word)) return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, n, m, board, word)) return true;
                }
            }
        }

        return false;
    }
};