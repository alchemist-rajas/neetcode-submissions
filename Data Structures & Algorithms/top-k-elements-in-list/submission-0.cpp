class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> counts;

        //key=number,  val = counts
        for( int num:nums){
            counts[num]++;
        }

        //bucket  array with index = freq counts
        //size is n+1 as freq can  range from o to n inclusive
        vector<vector<int>> buckets(n+1);
        for(const auto& [num,freq] : counts){
            buckets[freq].push_back(num);
        }

        vector<int> res;
        for(int i=n;i>=0;--i){
            for(int num:buckets[i]){
                res.push_back(num);
                //as soon as k collected return  result
                if(res.size()==k){
                    return res;
                }
            }
        }

        return res;
       
    }
};
