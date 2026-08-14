class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0)return 0;
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int maxi = 1;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                maxi = max(maxi, j-i);
                mp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};









// vector<int> hash(256,-1);
//         int n=s.size();
//         int left=0,right=0,maxlen=0,len=0;
//         while(right<n){
//             if(hash[s[right]]!=-1){
//                 if(hash[s[right]]>=left){
//                     left=hash[s[right]]+1;
//                 }
//             }
//             len=right-left+1;
//             maxlen=max(len,maxlen);
//             hash[s[right]]=right;
//             right++;
//         }
//         return maxlen;