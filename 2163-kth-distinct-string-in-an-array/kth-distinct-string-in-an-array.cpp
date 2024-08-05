class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        for(int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(freq[arr[i]] == 1) {
                if(k == 1) return arr[i];
                k--;
            }
        }

        return "";
    }
};