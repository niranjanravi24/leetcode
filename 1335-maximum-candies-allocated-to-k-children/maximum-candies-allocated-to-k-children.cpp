class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int ans = 0;
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        while(low<=high){
            int mid = (low+high)/2;

            long long totalPiles = 0;
            for(int i=0; i<n; i++){
                totalPiles += candies[i]/mid;
            }

            if(totalPiles >= k){
                ans = mid;
                low = mid+1;
                
            }
            else{
               high = mid -1;
            }
        }
        return ans;
    }
};