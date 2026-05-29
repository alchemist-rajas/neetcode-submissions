class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;

        for(const string& op : operations) {
            if(op == "+") {
                int top1 = stack.back();
                int top2 = stack[stack.size() -2];
                stack.push_back(top1+top2);
            } else if ( op == "D") {
                stack.push_back(stack.back()*2);
            } else if (op == "C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }

        int sum = 0;
        for( int score : stack) {
            sum += score;
        }

        return sum;
        
    }
};