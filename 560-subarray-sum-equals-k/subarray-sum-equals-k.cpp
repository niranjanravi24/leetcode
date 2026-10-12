class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pS = 0;
        int count = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            pS += nums[i];
            int rem = pS - k;
            count += mp[rem];
            mp[pS]++;
        }
        return count;
    }
};