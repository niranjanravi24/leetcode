class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int count = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int rem = prefixSum-k;    
            count += mp[rem];
            mp[prefixSum]++;
        }
        return count;
    }
};