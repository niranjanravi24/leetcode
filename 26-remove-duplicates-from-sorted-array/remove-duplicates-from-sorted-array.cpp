class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;

    }
};









       // int i=0;
        // for(int j=1;j<nums.size();j++){
        //     if(nums[i]!=nums[j]){
        //         i++;
        //         nums[i]=nums[j];
        //     }
        // }
        // return i+1;

    
    // int i=0;
    // for(int j=1; j<nums.size(); j++){
    //     if(nums[i] != nums[j]){
    //         i++;
    //         nums[i] = nums[j];
    //     }
    // }

    // return i+1;