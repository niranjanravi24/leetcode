class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++){
            int count = 0;
            vector<int> sub;
            for(int j=i; j<n; j++){
                if(nums[j]%p==0){
                    count++;
                }
                if(count > k){
                    break;
                }
                sub.push_back(nums[j]);
                st.insert(sub);
            }
        }
        return st.size();
    }
};