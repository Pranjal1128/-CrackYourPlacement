class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jmp = 0;
        if(r == nums.size() - 1) return 0;
        while(r < nums.size() - 1) {
            jmp++;
            int f = 0;
            for(int i = l; i <= r; i++) {
                f = max(f, i + nums[i]);
            }
            l = r + 1;
            r = f;
        }

        return jmp;
    }
};