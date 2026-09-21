class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        int i =0; int j = 0;
        string ans = "";
        while(j<n){
            while(i<n && s[i]==' '){
                i++;
            }
            j = i;

            while(j<n && s[j]!=' '){
                j++;
            }

            if(i<n){
                reverse(s.begin()+i, s.begin()+j);
                if(!ans.empty()){
                    ans += ' ';
                }
                ans += s.substr(i, j-i);
            }

            i = j;
        }

        return ans;
    }
};