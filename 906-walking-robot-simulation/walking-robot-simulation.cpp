class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> s;
        for(int i = 0; i < obstacles.size(); i++) {
            s.insert(to_string(obstacles[i][0]) + "_" + to_string(obstacles[i][1]));
        }

        int ans = 0, x = 0, y = 0;
        pair<int, int> dir = {0, 1};

        for(auto i:commands) {
            if(i == -1) {
                dir = {dir.second, -dir.first};
            }
            else if(i == -2) {
                dir = {-dir.second, dir.first};
            }
            else {
                for(int step = 0; step < i; step++) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    string next = to_string(nx) + "_" + to_string(ny);
                    if(s.find(next) != s.end()) break;
                    x = nx, y = ny;
                }
            }  

            ans = max(ans, x*x + y*y); 
        }

        return ans;
    }
};