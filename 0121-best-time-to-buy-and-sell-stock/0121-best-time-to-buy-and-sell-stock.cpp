class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int max_profit = 0;
      int small = prices[0];
      for(int i = 1; i<prices.size(); i++){
        int cost = prices[i]-small;
        max_profit = max(max_profit, cost);
        small = min(small, prices[i]);
      }
      return max_profit;  
    }
};