class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right =0;
        for(int weight : weights) {
            left = max(left,weight);
            right+= weight;
        }

        int res = right;
        while(left <= right) {
            int capacity = left + (right - left) /2 ;
            int daysNeeded = 1;
            int currentLoad = 0;
            
            for(int weight : weights) {
                if( currentLoad + weight > capacity) {
                    daysNeeded++;
                    currentLoad = weight;
                } else {
                    currentLoad += weight;
                }
            }

            if(daysNeeded <= days) {
                res = capacity;
                right = capacity -1;
            } else {
                left = capacity + 1;
            }
        }

        return res;
    }
};