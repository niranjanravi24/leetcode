class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int near = 0;
        int far = 0;
        while(far<nums.size()-1){
            int farthest = 0;
            for(int i=near; i<=far; i++){
                farthest = max(farthest, nums[i]+i);
            }
            near = far+1;
            far = farthest;
            if(!far) return false;
        }
        return true;
    }
};