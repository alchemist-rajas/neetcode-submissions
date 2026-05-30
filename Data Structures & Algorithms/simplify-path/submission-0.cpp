class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string currentDir = "";

        for(int i =0 ;  i <= path.length(); i++){
            if(i == path.length() || path[i] == '/') {
                if(currentDir == "..") {
                    if(!stack.empty()){
                        stack.pop_back();
                    }
                } else if (currentDir != "" && currentDir != ".") {
                    stack.push_back(currentDir);
                }
                currentDir = "";
            } else {
                currentDir += path[i];
            }
        }

        string result = "";

        for(const string& dir: stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
        
    }
};