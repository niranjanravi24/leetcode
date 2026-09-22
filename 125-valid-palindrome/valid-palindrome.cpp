class Solution {
public:
    bool isPalindrome(string s) {
        string constructed = "";
        int n = s.length();
        int i = 0;
        while(i<n){
            if(s[i]>='A' && s[i]<='Z'){
                constructed += s[i]+32;
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                constructed += s[i];
            }
            i++;
        }
        string og = constructed;
        reverse(constructed.begin(), constructed.end());
        string rev = constructed;
        return og == rev;
    }
};