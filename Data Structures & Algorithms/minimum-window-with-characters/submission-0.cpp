class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.length() < t.length()) return "";

        unordered_map<char,int> countT;
        for(char c:t){
            countT[c]++;
        }

        int have = 0,need = countT.size();
        int left = 0 ;
        int resLeft = -1,resLen = INT_MAX;
        unordered_map<char,int> window;

        for(int right = 0 ; right< s.length(); right++){
            char c = s[right];
            window[c]++;

            if(countT.count(c) && window[c]==countT[c]){
                have++;
            }

            while( have == need){
                if( right - left + 1 < resLen) {
                    resLen = right - left + 1 ;
                    resLeft = left;
                }

                char popChar = s[left];
                window[popChar]--;
                if(countT.count(popChar) && window[popChar] < countT[popChar]){
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "":s.substr(resLeft,resLen);
        
    }
};
