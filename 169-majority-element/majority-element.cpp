class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maj = n / 2;

        int count = 1;
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                count++;
            }
            else {
                count = 1;
            }

            if(count > maj) {
                ans = nums[i];
            }
        }

        return ans;
    }
};









// int n=nums.size();
        // int half=n/2;
        // int maj=-1;
        // map<int,int> mpp;
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it:mpp){
        //     if(it.second>half){
        //         maj=it.first;
        //     }
        // }
        // return maj;
