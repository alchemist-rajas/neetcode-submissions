class Solution {
public:
    string decodeString(string s) {
        vector<int> counts;
        vector<string> strings;
        string currentString = "";
        int currentCount = 0;

        for(char c : s) {
            if(isdigit(c)) {
                currentCount = currentCount*10 + (c-'0');
            } else if (c == '[') {
                counts.push_back(currentCount);
                strings.push_back(currentString);
                currentCount = 0;
                currentString = "";
            } else if (c == ']') {
                string decodedString = strings.back();
                strings.pop_back();

                int repeatCount = counts.back();
                counts.pop_back();

                for(int i =0; i < repeatCount ; i++){
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString +=c;
            }
        }

        return currentString;
    }
};