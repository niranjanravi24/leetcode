class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        int i = 0;
        while(i<size1){
            if(haystack.substr(i, size2) == needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};