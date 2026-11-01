class Solution {
    int f(vector<int>& nums,int index, vector<int>& dp){
        if(index == 0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];

        int pick = nums[index] + f(nums,index-2,dp);
        int notPick = 0 + f(nums,index-1,dp);

        return dp[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums, nums.size()-1, dp);
    }
};