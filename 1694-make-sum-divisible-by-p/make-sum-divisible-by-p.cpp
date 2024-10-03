class Solution {
public:
    int minSubarray(vector<int>& arr, int p) {
        vector<long long int> nums;
        for(int i = 0; i < arr.size(); i++) nums.push_back(arr[i]);
        long long tot = 0;
        for(auto i:nums) tot += i;
        unordered_map<long long, long long> mp;
        long long int key = tot % p, ans = INT_MAX, sum = 0;
        if(key == 0) return 0;
        
        mp[0]=0;
       int last=-1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= p;
            int q=(sum+p-key)%p;
            if(q==0)ans = min(ans, i - mp[q]+1);
            if(mp[q]) ans = min(ans, i - mp[q]+1);
            mp[sum] = i+1;
        }
       
        if(ans == nums.size()) ans = -1;
        return ans == INT_MAX ? -1 : ans;
    }
};