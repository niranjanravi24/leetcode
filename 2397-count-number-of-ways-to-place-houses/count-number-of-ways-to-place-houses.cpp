class Solution {
    const long long MOD = 1e9+7;
    int solve(int n, vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 2;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (solve(n-1, dp)+solve(n-2, dp))%MOD;

    }
public:
    int countHousePlacements(int n) {
        vector<int> dp(n+1,-1);
        long long ans = solve(n,dp);
        return (ans*ans)%MOD;
    }
};