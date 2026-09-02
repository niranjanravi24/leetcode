class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,r=0;
        int n=nums.size();
        int numsSum = 0;

        for(int i=0;i<n;i++){
            numsSum += nums[i];
        }
        if(numsSum < x) return -1;
        int k = numsSum - x;
        if(k == 0) return n;
        int sum = 0;
        int eleKept = 0;
        while(r<n){
            sum += nums[r];
            while(sum>k){
                sum -= nums[l];
                l++;
            }
            if(sum==k){
                eleKept = max(r-l+1,eleKept);
            }

            r++;
        }
        return eleKept==0 ?-1 : n-eleKept;
    }
};