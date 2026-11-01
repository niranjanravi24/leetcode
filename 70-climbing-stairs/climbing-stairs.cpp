class Solution {
    int solve(int n,int steps, vector<int>& dp){
        if(steps==n){
            return 1;
        }
        else if(steps > n){
            return 0;
        }
        if(dp[steps]!=-1) return dp[steps];
        
        int left = solve(n, steps+1, dp);
        int right = solve(n, steps+2, dp);

        return dp[steps] = left + right;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n, 0, dp);
        
    }
};