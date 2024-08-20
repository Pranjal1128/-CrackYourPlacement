class Solution {
public:
    // static bool comp(int p, int q) {
    //     if(p == 0) return false;
    //     if(q == 0) return true;
        
    //     if(p % 10 == q % 10) return comp(p/10, q/10);
    //     return p % 10 >= q % 10;
    // }

    static bool comp(int p, int q) {
        string a = to_string(p) + to_string(q);
        string b = to_string(q) + to_string(p);

        return a > b;
    }

    string largestNumber(vector<int>& nums) {
        string ans = "";
        int flag = 0;
        sort(nums.begin(), nums.end(), comp);
        for(int i = 0; i < nums.size(); i++) {
            if(ans.size() == 0 && nums[i] == 0) continue;
            ans += to_string(nums[i]);
        }
        if(!ans.size()) return "0";
        return ans;
    }
};
