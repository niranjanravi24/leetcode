class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.length();
        int s2 = needle.length();
        int i = 0;
        while(i<s1){
            if(haystack.substr(i,s2)==needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};