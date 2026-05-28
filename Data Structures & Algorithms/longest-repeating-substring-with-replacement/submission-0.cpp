class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> counts;
        int left = 0;
        int maxLength = 0;
        int maxFrequency = 0;

        for(int right = 0; right< s.length(); right++) {
            counts[s[right]] ++;
            maxFrequency = max(maxFrequency,counts[s[right]]);

            int windowLength = right - left + 1;
            if(windowLength - maxFrequency > k){
                counts[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right -left + 1);
        }

        return maxLength;
        
    }
};
