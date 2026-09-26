class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,char> st, ts;

        for(int i=0; i<s.length(); i++){

            char ss = s[i];
            char tt = t[i];

            if(st.count(ss)){
                if(st[ss]!=tt){
                    return false;
                } 
            }
            else{
                st[ss] = tt;
            }        

            if(ts.count(tt)){
                if(ts[tt]!=ss){
                    return false;
                } 
            }
            else{
                ts[tt] = ss;
            } 
        }
        return true;
    }
};