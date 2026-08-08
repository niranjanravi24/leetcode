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
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    
        // for(int ind=0; ind<n; ind++){
        //     for(int buy=0; buy<=1; buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // for(int buy=0; buy<=1; buy++){
        //     for(int count=0; count<=2; count++){
        //         dp[n][buy][count] = 0;
        //     }
        // }

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int count=1; count<=2; count++){
                  long profit = 0;
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
        return dp[0][1][2];
    }
};