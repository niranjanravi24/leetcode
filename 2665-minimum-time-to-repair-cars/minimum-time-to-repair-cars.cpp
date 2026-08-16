class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 1;
        long long high = *max_element(ranks.begin(), ranks.end())*1LL*cars*cars;
        long long ans = LLONG_MAX;

        while(low<=high){
            long long mid = (low+high)/2;

            long long count = 0;
            for(int i=0; i<n; i++){
                count += sqrt(mid/ranks[i]);
            }

            if(count >= cars){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};