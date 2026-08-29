class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};
        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = delRow[i]+r;
                int nCol = delCol[i]+c;
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && 
                vis[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;
    }
};