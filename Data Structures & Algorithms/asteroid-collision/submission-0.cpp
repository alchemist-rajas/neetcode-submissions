class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int asteroid : asteroids) {
            bool  exploded = false;

            while(!stack.empty() && asteroid<0 && stack.back()>0) {
                if(stack.back() < -asteroid){
                    stack.pop_back();
                    continue;
                } else if (stack.back() == -asteroid) {
                    stack.pop_back();
                }
                exploded = true;
                break;
            }

            if(!exploded) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};