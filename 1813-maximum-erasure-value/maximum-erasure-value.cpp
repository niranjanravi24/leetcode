class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int l=0;int r=0;
        int maxSum=0;int sum=0;
        while(r<nums.size()){
            if(mp.count(nums[r])){
                while(mp[nums[r]]>0){
                    mp[nums[l]]--;
                    sum -= nums[l];
                    l++;
                }
            }
            mp[nums[r]]++;
            sum += nums[r];
            maxSum = max(maxSum,sum);
            r++;
        }
        return maxSum;
    }
};