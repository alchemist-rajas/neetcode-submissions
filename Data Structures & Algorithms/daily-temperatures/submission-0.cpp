class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        vector<int> stack;

        for(int i  =0 ; i < temperatures.size(); i ++){
            while(!stack.empty() && temperatures[i]>temperatures[stack.back()]) {
                int prevIndex = stack.back();
                stack.pop_back();
                result[prevIndex] = i - prevIndex;
            }

            stack.push_back(i);
        }

        return result;
    }
};
