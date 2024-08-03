class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        if(t.size() != a.size()) return false;
        sort(t.begin(), t.end());
        sort(a.begin(), a.end());
        for(int i = 0; i < t.size(); i++) {
            if(t[i] != a[i]) return false;
        }
        return true;
    }
};