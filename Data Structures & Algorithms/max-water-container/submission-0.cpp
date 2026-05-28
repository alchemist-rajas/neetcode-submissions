class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() -1;
        int maxWater = 0;

        while(left< right){
            int currentWidth = right - left;
            int currentHeight = min(heights[left],heights[right]);
            maxWater = max(maxWater, currentWidth*currentHeight);

            if(heights[left] < heights[right]){
                left++;
            } else{
                right--;
            }
        }

        return maxWater;
        
    }
};
