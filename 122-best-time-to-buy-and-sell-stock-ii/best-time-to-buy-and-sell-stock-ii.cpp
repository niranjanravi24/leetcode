class Solution {
    int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[index]+f(index+1, 0, prices, dp), 0+f(index+1, 1, prices, dp));
        }
        else{
            profit = max(prices[index]+f(index+1, 1, prices, dp), 0+f(index+1, 0, prices, dp));
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        // 2
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2,0));
        // 3 space;
        vector<int> aHead(2,0);
        vector<int> curr(2,0);
        aHead[0] = 0;
        aHead[1] = 0;
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index]+aHead[0], 0+ aHead[1]);
                    }
                    else{
                        profit = max(prices[index]+ aHead[1], 0+ aHead[0]);
                    }

                    curr[buy] = profit; 
            }
            aHead = curr;
        }
        return aHead[1];
    }
};