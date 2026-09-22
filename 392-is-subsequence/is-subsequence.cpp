class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.length() && !t.length()) return true;

        int i = 0;
        int j = 0;
        int sLen = s.length();
        int count = 0;
        while(j<t.length()){
            if(s[i]==t[j]){
                count++;
                i++;
            }

            if(count == sLen){
                return true;
            }

            j++;
        }
        return false;
    }
};