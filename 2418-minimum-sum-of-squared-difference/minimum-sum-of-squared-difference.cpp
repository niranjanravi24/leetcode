class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long n = nums1.size();
        int maxi = INT_MIN;
        long long k = 1LL*k1+k2;
        vector<int> diff(n);
        for(int i=0; i<n; i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            maxi = max(maxi,diff[i]);
        }

        vector<int> bucket(maxi+1);
        for(int i : diff){
            bucket[i]++;
        }
        for(int i=maxi; i>0 && k>0; i--){
            int take = min((long long)bucket[i],k);
            bucket[i] -= take;
            bucket[i-1] += take;
            k -= take;
        }

        long long ans = 0;
        for(int i=1; i<bucket.size(); i++){
            ans += 1LL*bucket[i]*i*i;
        }
        return ans;
    }
};