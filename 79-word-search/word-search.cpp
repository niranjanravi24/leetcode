class Solution {
bool dfs(int row, int col, string& word,
         vector<vector<char>>& board,
         int index,
         vector<vector<int>>& vis){

    if(index == word.size()-1){
        return true;
    }

    vis[row][col] = 1;

    int m = board.size();
    int n = board[0].size();

    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow>=0 && nRow<m &&
           nCol>=0 && nCol<n &&
           !vis[nRow][nCol] &&
           board[nRow][nCol] == word[index+1]){

            if(dfs(nRow, nCol, word, board, index+1, vis)){
                return true;
            }
        }
    }

    vis[row][col] = 0;
    return false;
}
public:
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> vis(m, vector<int>(n,0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){

            if(board[i][j] == word[0]){

                if(dfs(i, j, word, board, 0, vis)){
                    return true;
                }

            }
        }
    }

    return false;

    }
};