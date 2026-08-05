class Solution {
    void f(vector<int>& nums, vector<vector<int>>& final, vector<int>& each, vector<bool>& vis){
        if(each.size() == nums.size()){
            final.push_back(each);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(vis[i]){
                continue;
            }
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1]){
                continue;
            }
            vis[i] = true;
            each.push_back(nums[i]);

            f(nums, final, each, vis);

            each.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> final;
        vector<int> each;
        vector<bool> vis(nums.size(), 0);

        f(nums, final, each, vis);
        
        return final;
    }
};