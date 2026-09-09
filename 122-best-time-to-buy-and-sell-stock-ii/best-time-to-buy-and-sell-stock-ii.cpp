class Solution {
    int f(vector<int>& prices, int buy, int index, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[index]+f(prices,0,index+1,dp), 0+f(prices,1,index+1,dp));
        }
        else{
            profit = max(prices[index]+f(prices,1,index+1,dp), 0+f(prices,0,index+1,dp));
        }
        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int index = 0;
        int buy = 1;
        vector<vector<int>>dp (n, vector<int>(2,-1));
        return f(prices, buy, index, dp);
    }

};