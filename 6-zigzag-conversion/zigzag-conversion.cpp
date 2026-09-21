class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows==1) return s;
       int n = s.length();
       int jumps = (numRows-1)*2;
       string ans = "";
       for(int i=0; i<numRows; i++){
        for(int j=i; j<n; j+=jumps){
            ans += s[j];
            if(i>0 && i<numRows-1 && (j+jumps-2*i)<n){
                ans += s[j+jumps-2*i];
            }
        }
       }
       return ans; 
    }
};