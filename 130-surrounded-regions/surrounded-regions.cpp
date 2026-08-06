class Solution {
    void dfs(int row, int col, vector<vector<char>>& board, vector<int>& delRow, vector<int>& delCol, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol] && board[nRow][nCol]=='O'){
                dfs(nRow, nCol, board, delRow, delCol, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};

        for(int i=0; i<n; i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,delRow,delCol,vis);
            }

            if(!vis[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1,i,board,delRow,delCol,vis);
            }
        }

        for(int i=0; i<m; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,delRow,delCol,vis);
            }

            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,delRow,delCol,vis);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};