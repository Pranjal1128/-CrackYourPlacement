class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        pq.push({points[0][1] - points[0][0], points[0][0]});
        for(int i = 1; i < points.size(); i++) {
            while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();
            if(!pq.empty()) ans = max(ans, pq.top().first + points[i][1] + points[i][0]);
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }

        return ans;
    }
};