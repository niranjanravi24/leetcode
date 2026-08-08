class Solution {
    long f(int ind, int buy, vector<int>& prices, int count, vector<vector<vector<int>>>& dp){
        if(ind == prices.size()){
            return 0;
        }
        if(count == 0){
            return 0;
        }
        if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,prices,count,dp), 0+f(ind+1,1,prices,count,dp));
        }
        else{
            profit = max(prices[ind]+f(ind+1,1,prices,count-1,dp), 0+f(ind+1,0,prices,count,dp));
        }
        return dp[ind][buy][count] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,prices,2,dp);
    }
};