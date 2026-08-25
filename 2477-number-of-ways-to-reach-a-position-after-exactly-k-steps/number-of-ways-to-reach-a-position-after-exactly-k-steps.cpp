class Solution {
    const int MOD = 1e9 + 7;

    int find(int pos, int end, int k, vector<vector<int>>& dp, int offset) {
        if(k == 0) {
            return pos == end;
        }

        if(dp[pos + offset][k] != -1)
            return dp[pos + offset][k];

        return dp[pos + offset][k] =
            (find(pos + 1, end, k - 1, dp, offset) +
             find(pos - 1, end, k - 1, dp, offset)) % MOD;
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        int offset = k + 1;
        int size = 2 * k + 3;

        vector<vector<int>> dp(size, vector<int>(k + 1, -1));

        // Make startPos = 0
        int relativeEnd = endPos - startPos;

        return find(0, relativeEnd, k, dp, offset);
    }
};