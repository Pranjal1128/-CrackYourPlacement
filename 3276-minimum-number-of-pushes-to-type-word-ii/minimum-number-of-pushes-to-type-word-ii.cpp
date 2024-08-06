class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(int i = 0; i < word.size(); i++) {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0, cnt = 0, mult = 1;
        for(auto i:freq) {
            if(cnt == 8) {
                cnt = 0;
                mult++;
            }
            ans += (mult*i);
            cnt++;
        }
        return ans;
    }
};