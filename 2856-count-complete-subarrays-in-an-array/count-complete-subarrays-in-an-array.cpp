class Solution {
    int atmost(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int k = st.size();

        return atmost(nums,k) - atmost(nums,k-1);

    }
};