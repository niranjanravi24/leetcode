class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        int oldColor = image[sr][sc];
        q.push({sr,sc});

        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second; 
            q.pop();

            vector<int> delRow = {-1,0,1,0};
            vector<int> delCol = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow = delRow[i]+row;
                int nCol = delCol[i]+col;

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && image[nRow][nCol]==oldColor && !vis[nRow][nCol]){
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = 1;
                    image[nRow][nCol] = color;
                }
            }
        }
        return image;
    }
};