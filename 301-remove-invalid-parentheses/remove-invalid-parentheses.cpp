class Solution {
public:

    void solve(int i, string& curr, string& s,
               int leftRemove, int rightRemove,
               int balance, unordered_set<string>& st) {

        if(balance < 0)
            return;

        if(i == s.length()) {
            if(balance == 0 && leftRemove == 0 && rightRemove == 0)
                st.insert(curr);
            return;
        }

        if(s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(i+1, curr, s, leftRemove, rightRemove,
                  balance, st);
            curr.pop_back();
            return;
        }

        // Remove current parenthesis
        if(s[i] == '(' && leftRemove > 0) {
            solve(i+1, curr, s,
                  leftRemove-1, rightRemove,
                  balance, st);
        }

        if(s[i] == ')' && rightRemove > 0) {
            solve(i+1, curr, s,
                  leftRemove, rightRemove-1,
                  balance, st);
        }

        // Keep current parenthesis
        curr.push_back(s[i]);

        if(s[i] == '(')
            solve(i+1, curr, s,
                  leftRemove, rightRemove,
                  balance+1, st);
        else
            solve(i+1, curr, s,
                  leftRemove, rightRemove,
                  balance-1, st);

        curr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }
            else if(c == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        unordered_set<string> st;
        string curr = "";

        solve(0, curr, s,
              leftRemove, rightRemove,
              0, st);

        return vector<string>(st.begin(), st.end());
    }
};