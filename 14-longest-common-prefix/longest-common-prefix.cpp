class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1 && strs[0]=="") return "";
        string fix = strs[0];
        int count = INT_MAX;
        for(int i=1; i<n; i++){
            string check = strs[i];
            int cnt = 0;
            for(int i=0; i<fix.length(); i++){
                if(fix[i]==check[i]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            count = min(cnt, count);
        }
        if(count == INT_MAX){
            count = 1;
        }
        string res = "";
        for(int i=0; i<count; i++){
            res += fix[i];
        }
        return res;
    }
};