class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int max_profit = 0;

        for(int right = 1; right < prices.size(); right++){
            if(prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                max_profit = max(max_profit,profit);
            } else {
                left = right;
            }
        }

        return max_profit;
        
    }
};
