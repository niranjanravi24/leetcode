class Solution {
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid,
    vector<int>& delRow, vector<int>& delCol){
        vis[row][col]=1;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n &&
                    grid[nRow][nCol]=='1' && !vis[nRow][nCol] ){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    bfs(i,j,vis,grid,delRow,delCol);
                    
                }
            }
        }
        return count;
    }
};