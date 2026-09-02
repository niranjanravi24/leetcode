class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        int sum = 0;
        for(int i=0; i<n; i++){
            leftSum[i] += sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i=n-1; i>=0; i--){
            rightSum[i] += sum;
            sum += nums[i];
        }

        for(int i=0; i<n; i++){
            if(leftSum[i]==rightSum[i]){
                return i;
            }
        }
        return -1;
    }
};