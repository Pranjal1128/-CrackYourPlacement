class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1;

        if(height.size() == 1){
            return 0;
        }

        else{
            int area = 0;
            while(i < j){
                int key = (j - i)*min(height[i],height[j]);
                if(key > area){
                    area = key;
                }
                if(height[i] >= height[j]){
                    j--;
                }
                else{
                    i++;
                }
            }
            return area;
        }
    }
};