class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int l=0;int r=0;
        int mini = INT_MAX;
        unordered_map<int,int> mp;
        while(r<n){
            mp[cards[r]]++;
            while(mp[cards[r]] > 1){
                mp[cards[l]]--;
                mini = min(mini,r-l+1);
                l++;
            }
            r++;
        }
        return mini==INT_MAX ? -1:mini;
    }
};