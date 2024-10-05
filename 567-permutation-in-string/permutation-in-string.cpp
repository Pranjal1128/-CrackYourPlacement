class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        map<char, int> mp;
        for(int i = 0; i < s1.size(); i++) {
            mp[s1[i]]++;
        }
        map<char, int> temp;
        for(int i = 0; i < s1.size(); i++) {
            temp[s2[i]]++;
        }

        if(mp == temp) return true;
        int l = 0;
        for(int i = s1.size(); i < s2.size(); i++) {
            temp[s2[i]]++;
            if(temp[s2[l]] == 1) temp.erase(s2[l++]);
            else temp[s2[l++]]--;
            if(mp == temp) return true;
        }

        return false;
    }
};