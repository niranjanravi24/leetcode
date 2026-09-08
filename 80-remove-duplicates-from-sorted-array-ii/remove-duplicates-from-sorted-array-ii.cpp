class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int index = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                count++;
                if(count<=2){
                    index++;
                    nums[index] = nums[i];
                }
            }
            else{
                count = 1;
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};