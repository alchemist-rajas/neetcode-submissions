class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char,char> matching = {{')','('},{'}','{'},{']','['}};

        for(char c : s) {
            if(matching.count(c)) {
                if(!stack.empty() && stack.back() == matching[c]) {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else {
                stack.push_back(c);
            }
        }

        return stack.empty();
        
    }
};
