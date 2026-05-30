class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<pair<int,int>> stack;

        for(int i =0; i < heights.size();i++){
            int start = i;

            while(!stack.empty() && stack.back().second > heights[i]) {
                int index = stack.back().first;
                int height = stack.back().second;
                stack.pop_back();

                maxArea = max(maxArea, height*(i-index));
                start = index;
            }

            stack.push_back({start,heights[i]});
        }

        for(int i =0; i < stack.size(); i++){
            int currentArea = stack[i].second*(heights.size() - stack[i].first);
            maxArea = max(maxArea,currentArea);
        }

        return maxArea;
        
    }
};
