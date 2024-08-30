class DisjointSet {
    
    public:
    vector<int> rank, par, size;
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            par.resize(n + 1);
            size.resize(n + 1, 1);
            
            for(int i = 0; i <= n; i++) {
                par[i] = i;
            }
        }
        
        int findPar(int n) {
            if(n == par[n]) return n;
            
            return par[n] = findPar(par[n]);
        }
        
        void unionByRank(int u, int v) {
            int up_u = findPar(u);
            int up_v = findPar(v);
            if(up_u == up_v) return;
            
            if(rank[up_u] < rank[up_v]) {
                par[up_u] = up_v;
            }
            else if(rank[up_u] > rank[up_v]) {
                par[up_v] = up_u;
            }
            else {
                par[u] = up_v;
                rank[up_u]++;
            }
        }
        
       void unionBySize(int u, int v) {
            int up_u = findPar(u);
            int up_v = findPar(v);
            if(up_u == up_v) return;
            
            if(size[up_u] < size[up_v]) {
                par[up_u] = up_v;
                size[up_v] += size[up_u];
            }
            else {
                par[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        int m = 0;
        for(auto i:stones) {
            n = max(n, i[0]);
            m = max(m, i[1]);
        }

        DisjointSet ds(n + m + 1); 
        unordered_map<int, int> mp; 
        for(auto it:stones) {
            int rowNo = it[0];
            int colNo = it[1] + n + 1;

            ds.unionBySize(rowNo, colNo);
            mp[rowNo] = 1;
            mp[colNo] = 1;
        }
        int cnt = 0;
        for(auto i:mp) {
            if(i.first == ds.findPar(i.first)) cnt++;
        }

        return stones.size() - cnt;
    }
};