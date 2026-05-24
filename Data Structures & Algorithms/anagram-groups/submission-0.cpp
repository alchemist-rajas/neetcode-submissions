class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>>groups;

            for(const string&s : strs)
            {
                string signature =s ;
                sort(signature.begin(),signature.end());

                groups[signature].push_back(s);
            }

            vector<vector<string>> res;

            for(const auto& pair : groups)
            {
                res.push_back(pair.second);
            }

            return res;

    }
};
