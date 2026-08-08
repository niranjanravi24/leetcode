class Solution {
    int f(int ind, int buy, int count, vector<int>& prices, vector<vector<vector<int>>> & dp){
        if(count==0 || ind == prices.size()){
            return 0;
        }
        if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,count,prices,dp), 0+f(ind+1,1,count,prices,dp));
        }
        else{
            profit = max(prices[ind]+f(ind+1,1,count-1,prices,dp), 0+f(ind+1,0,count,prices,dp));
        }
        return dp[ind][buy][count] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};