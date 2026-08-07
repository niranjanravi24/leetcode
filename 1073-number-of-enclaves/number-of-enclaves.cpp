class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
    vector<int>& delRow, vector<int>& delCol){
        vis[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n &&
            !vis[nRow][nCol] && grid[nRow][nCol]){
                dfs(nRow, nCol, grid, vis, delRow, delCol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector(n,0));
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};
        int count = 0;

        for(int i=0; i<n; i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,grid,vis,delRow,delCol);
            }
            if(!vis[m-1][i] && grid[m-1][i]==1){
                dfs(m-1,i,grid,vis,delRow,delCol);
            }
        }

        for(int i=0; i<m; i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis,delRow,delCol);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,grid,vis,delRow,delCol);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};