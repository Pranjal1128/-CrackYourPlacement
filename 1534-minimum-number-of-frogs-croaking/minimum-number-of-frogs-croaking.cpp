class Solution {
public:
    int minNumberOfFrogs(string cf) {
        unordered_map<char, int> cnt;
        cnt['c'] = cnt['r'] = cnt['o'] = cnt['a'] = cnt['k'] = 0;

        for(int i = 0; i < cf.size(); i++) {
            if(cf[i] == 'c') {
                cnt['c']++;
                if(cnt['k']) cnt['k']--;
            }
            else if(cf[i] == 'r') {
                if(cnt['c'] <= 0) return -1;
                cnt['r']++;
                cnt['c']--;
            } 
            else if(cf[i] == 'o') {
                if(cnt['r'] <= 0) return -1;
                cnt['o']++;
                cnt['r']--;
            } 
            else if(cf[i] == 'a') {
                if(cnt['o'] <= 0) return -1;
                cnt['a']++;
                cnt['o']--;
            } 
            else if(cf[i] == 'k') {
                if(cnt['a'] <= 0) return -1;
                cnt['k']++;
                cnt['a']--;
            } 
        }

        for(auto i:cnt) {
            if(i.first != 'k' && i.second != 0) return -1;
        }

        return cnt['k'];
    }
};