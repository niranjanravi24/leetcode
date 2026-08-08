class Solution {
    int f(int index, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[index]+f(index+1,0,prices,fee,dp), 0+f(index+1,1,prices,fee,dp));
        }else{
            profit = max(prices[index]-fee+f(index+1,1,prices,fee,dp), 0+f(index+1,0,prices,fee,dp));
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[index]+f(index+1,0,prices,fee,dp), 0+f(index+1,1,prices,fee,dp));
                }else{
                    profit = max(prices[index]-fee+f(index+1,1,prices,fee,dp), 0+f(index+1,0,prices,fee,dp));
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};