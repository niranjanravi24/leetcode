class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int pre = 0;
        for(int i=0; i<n; i++){
            int suf = total - nums[i] - pre;
            if(pre == suf){
                return i;
            }
            pre += nums[i];
        }

        return -1;
    }
};