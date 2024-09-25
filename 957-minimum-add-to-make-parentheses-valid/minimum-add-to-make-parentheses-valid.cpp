class Solution {
public:
    int minAddToMakeValid(string s) {
        int o = 0, iv = 0;
        for(int i = 0; i < s.size(); i++) {
            if(o == 0 && s[i] == ')') {
                iv++;
            } 
            else if(s[i] == '(') o++;
            else o--;
        }

        return o + iv;
    }
};