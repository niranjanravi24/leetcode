class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};








// vector <int> temp(0,k);
        // int n = nums.size();

        // for(int i=0; i<k; i++){
        //     temp.push_back(nums[n-k+i]);
        // }

        // for(int j=n-1; j>k-1; j--){
        //     nums[j] = nums[j-k];
        // }

        // // for(int l=0; l<k; l++){
        // //     nums[l] = temp[l];
        // // }
        
        // int n = nums.size();
        // k = k % n;
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());

        // for(int i=0; i<n; i++){
        //     cout<<nums[i]<<" ";
        // }