class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans(nums.size());
        mp[-1] = 0;
        for(int i=0; i<nums.size(); i++){
            ans[i] = mp[i-1] + nums[i];
            mp[i] = ans[i];
        }
        return ans;
    }
};