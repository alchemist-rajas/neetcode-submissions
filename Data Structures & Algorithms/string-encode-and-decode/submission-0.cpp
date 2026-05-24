class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string&s : strs){
            //pattern: [length] + [#] + [original string]
            encoded+= to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> decoded_strs;
        int i=0;

        while(i<s.length()){
            //find the position of the "#" delimiter starting from index i
            int j=i;

            while(s[j]!='#'){
                j++;
            }

            //extract the length of the string 
            int length  = stoi(s.substr(i,j-i));

            //move our reading head past the '#' delimiter
            i=j+1;

            //extract the original string using length
            string original_str = s.substr(i,length);
            decoded_strs.push_back(original_str);

            //move our reading head to the start of the next encoded block
            i+= length;
        }

        return  decoded_strs;

    }
};

