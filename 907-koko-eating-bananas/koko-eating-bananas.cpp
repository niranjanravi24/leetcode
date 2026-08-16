class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            double hours = 0;
            for(int i=0; i<piles.size(); i++){
                hours += ceil(double(piles[i])/double(mid));
            }

            if(hours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    
    }

};