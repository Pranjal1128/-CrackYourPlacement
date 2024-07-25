class Solution {
public:
    void merge(vector<int>& nums, int s, int m, int e) {
        int n1 = m - s + 1;
        int n2 = e - m;
        vector<int> A(n1), B(n2);
        for(int i = 0; i < n1; i++) A[i] = nums[s + i];
        for(int i = 0; i < n2; i++) B[i] = nums[m + 1 + i];
        int i = 0, j = 0, k = s;

        while(i < n1 && j < n2) {
            if(A[i] <= B[j]) {
                nums[k] = A[i++];
            } 
            else {
                nums[k] = B[j++];
            }
            k++;
        }

        while(i < n1) {
            nums[k++] = A[i++];
        }

        while(j < n2) {
            nums[k++] = B[j++];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if(s >= e) return;

        int m = s + (e - s)/2;
        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);

        merge(nums, s, m, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    } 
};