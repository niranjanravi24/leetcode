class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i=1;
        
        for(int i=0; i<nums.size()-1; i++){
            int curr = nums[i];
            int next = nums[i+1];
            while(curr+1 != next){
                curr++;
                ans.push_back(curr);
            }
        }
        return ans;
        
        return ans;
    }
};