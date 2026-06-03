class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0 ,right =0;
        for(int num : nums) {
            left = max(left,num);
            right += num;
        }

        int res = right;
        while(left <= right){
            int mid = left + (right - left) /2;
            int subarrays = 1;
            int currentSum = 0;

            for(int num : nums) {
                if(currentSum + num > mid) {
                    subarrays++;
                    currentSum = num;
                } else {
                    currentSum += num;
                }
            }

            if(subarrays<=k) {
                res = mid;
                right = mid -1;
            } else{
                left = mid + 1;
            }
        }

        return res;
    }
};