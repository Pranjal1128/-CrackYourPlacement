class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        for(int i = 0; i < o.size(); i++) {
            adj[o[i] - 'a'][c[i] - 'a'] = min(adj[o[i] - 'a'][c[i] - 'a'], cost[i]); 
        }
        for (int i = 0; i < 26; i++) adj[i][i] = 0;
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min((long long)adj[i][j], (long long)adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(adj[s[i] - 'a'][t[i] - 'a'] == INT_MAX) return -1;
            ans += adj[s[i] - 'a'][t[i] - 'a'];
        }
        return ans;
    }
};