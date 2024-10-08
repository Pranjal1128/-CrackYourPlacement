class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int t = arr[0] - 1;
        int n = arr.size();
        if(t >= k) return k;
        for(int i = 0; i < arr.size() - 1; i++) {
            t += (arr[i + 1] - arr[i] - 1);
            if(t >= k) {
                return k + i + 1;   //arr[i] + k - (arr[i] - (i + 1))
            }
        }

        return k + n;  //arr[n - 1] + k - (arr[n - 1] - n)
    }
};