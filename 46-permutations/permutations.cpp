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
            vis[i] = true;
            each.push_back(nums[i]);

            f(nums, final, each, vis);

            each.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> final;
        vector<int> each;
        vector<bool> vis(nums.size(), false);

        f(nums, final, each, vis);
        return final;
    }
};