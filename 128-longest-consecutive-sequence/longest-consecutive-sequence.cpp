class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int longest = -1;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count = 0;
                int num = it;
                while(st.find(num)!=st.end()){
                    count++;
                    num += 1;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};