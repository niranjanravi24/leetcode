class Solution {
    void f(vector<string>& res, int left,int right, int n, string ans){
        if(right==n && left==n){
            res.push_back(ans);
            return;
        }
        if(right > left){
            return ;
        }
        if(left<n){
            f(res, left+1, right, n, ans+'(') ;
        }
        if(right<n){
            f(res, left, right+1, n, ans+')');
        }
        

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(res, 0, 0, n, "");
        return res;
    }
};