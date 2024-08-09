class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
        int sum = 0;
        unordered_map<int, int> mp;

        // Check and count unique numbers between 1 and 9
        for(int k = i; k < i + 3; k++) {
            for(int l = j; l < j + 3; l++) {
                if(grid[k][l] > 9 || grid[k][l] == 0) return false;
                if(mp[grid[k][l]]++) return false;
            }
        }

        // Check rows
        for(int k = i; k < i + 3; k++) {
            int temp = 0;
            for(int l = j; l < j + 3; l++) {
                temp += grid[k][l];
            }
            if(sum == 0) sum = temp; // Initialize sum
            else if(sum != temp) return false;
        }

        // Check columns
        for(int k = j; k < j + 3; k++) {
            int temp = 0;
            for(int l = i; l < i + 3; l++) {
                temp += grid[l][k];
            }
            if(sum != temp) return false;
        }

        // Check main diagonal
        int temp = 0;
        for(int k = 0; k < 3; k++) {
            temp += grid[i + k][j + k];
        }
        if(temp != sum) return false;

        // Check anti-diagonal
        temp = 0;
        for(int k = 0; k < 3; k++) {
            temp += grid[i + k][j + 2 - k];
        }
        if(temp != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i <= n - 3; i++) {
            for(int j = 0; j <= m - 3; j++) {
                if(check(i, j, grid)) cnt++;
            }
        }      

        return cnt;
    }
};
