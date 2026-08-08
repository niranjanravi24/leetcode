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
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int count=1; count<=k; count++){
                   int profit = 0;
                    if(buy){
                        profit = max(-prices[ind]+dp[ind+1][0][count], 0+dp[ind+1][1][count]);
                    }
                    else{
                        profit = max(prices[ind]+dp[ind+1][1][count-1], 0+dp[ind+1][0][count]);
                    }
                    dp[ind][buy][count] = profit; 
                }
            }
        }
        return dp[0][1][k];
    }
};