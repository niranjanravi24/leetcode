class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dis(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i=0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n &&
                vis[nRow][nCol]==0){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps+1});
                }
            }
        }
        return dis;
    }
};