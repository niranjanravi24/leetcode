class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        vector<int> hash(256,-1);
        while(j<n){
            if(hash[s[j]]!=-1){
                if(hash[s[j]]>=i){
                    i = hash[s[j]] + 1;
                }
            }
            maxLen = max(maxLen, j-i+1);
            hash[s[j]] = j;
            j++;

        }
        return maxLen;
    }
};