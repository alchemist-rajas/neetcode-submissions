class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() >  s2.length()) return false;

        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);

        for(int i = 0; i < s1.length(); i++){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }

        int matches = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(s1Count[i] == s2Count[i]) matches++;
        }
        
        int left =0 ;
        for(int right = s1.length(); right < s2.length(); right++){
            if(matches == 26) return true;

            int index = s2[right] - 'a';
            s2Count[index]++;
            if(s1Count[index] == s2Count[index]) {
                matches++;
            } else if ( s1Count[index] + 1 == s2Count[index]){
                matches--;
            }

            index = s2[left] -'a';
            s2Count[index]--;
            if(s1Count[index] == s2Count[index]) {
                matches++;
            } else if ( s1Count[index] - 1 == s2Count[index]){
                matches--;
            }
            left++;
        }

        return  matches==26;
    }
};
