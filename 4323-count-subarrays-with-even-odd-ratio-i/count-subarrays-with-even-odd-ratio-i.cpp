class Solution {
    // int helper(vector<int>& nums, int limit, int index){
        
        
    // }
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int x = 0;
            int y = 0;
            for(int j=i; j<n; j++){
                
                if(nums[j]%2==0) x++;
                else y++;
                if(y>0 && (x*b) <= (a*y)){
                    count++;
                }
            }
        }
        return count;
    }
};