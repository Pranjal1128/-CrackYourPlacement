class Solution {
public:
    vector<int> PGE(vector<int> height, int n) {
        vector<int> ans(n, -1);
        for(int i = 1; i < n; i++) {
           ans[i] = max(ans[i - 1], height[i - 1]) > height[i] ? max(ans[i - 1], height[i - 1]) : -1;
        }

        return ans;
    }

    vector<int> NGE(vector<int> height, int n) {
        vector<int> ans(n, -1);
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i + 1], height[i + 1]) > height[i] ? max(ans[i + 1], height[i + 1]) : -1;
        }

        return ans;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pge = PGE(height, n); 
        vector<int> nge = NGE(height, n);
        int ans = 0, i = 0;
        while(i < n) {
           if(pge[i] != -1 && nge[i] != -1) {
                int h = min(pge[i], nge[i]);
                ans += (h - height[i]);
           }
           i++;
        }

        return ans;
    }
};