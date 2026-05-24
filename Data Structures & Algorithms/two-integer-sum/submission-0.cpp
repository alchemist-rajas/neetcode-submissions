class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> seen;
        for(int i =0; i<nums.size();++i){
            int complement =  target - nums[i];

            if(seen.count(complement)){
                return  {seen[complement],i}; //found it
                        //seen[complement] is the smaller index here , 
            }

            //we did not find it yet , so atleast store this one
            seen[nums[i]]=i;
            //eg seen[7]=2 ,  number 7 at  index 2
        }

        return {};
        //nothin found.
        
    }
};
