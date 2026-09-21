class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.length();
        int i=n-1;
        while(s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            count = count+1;
            i--;
        }
        return count;
    }
};