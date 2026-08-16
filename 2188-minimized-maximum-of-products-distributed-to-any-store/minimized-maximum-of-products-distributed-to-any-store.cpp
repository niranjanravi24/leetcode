class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int size = quantities.size();
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            double totalStores = 0;
            for(int i=0; i<size; i++){
                totalStores += ceil(double(quantities[i])/double(mid));
            }
            if(totalStores > n){
                low = mid+1;
            }
            else{
                ans = min(ans,mid);
                high = mid-1;
            }

        }
        return ans;
    }
};