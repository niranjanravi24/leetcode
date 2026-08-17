class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;

            int totalDays = 1;int wei = 0;
            for(int i=0; i<weights.size(); i++){
                if(wei+weights[i] > mid){
                    totalDays++;
                    wei = 0;
                }
                wei += weights[i];
            }
            if(totalDays > days){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};