class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int l=0,r=0;
        int ans=0,prod=1;
        int n=nums.size();
        while(r<n){
            prod *= nums[r];

            while(prod>=k){
                prod = prod/nums[l];
                l++;
            }

            ans += r-l+1;
            r++;
        }
        return ans;

    }
};