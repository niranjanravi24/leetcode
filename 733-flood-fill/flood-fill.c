/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Node{
    int r;
    int c;
};

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];

    *returnSize = m;
    *returnColumnSizes = malloc(m*sizeof(int));
    for(int i=0; i<m; i++){
        (*returnColumnSizes)[i] = n;
    }

    int oldColor = image[sr][sc];
    image[sr][sc] = color;

    struct Node* queue = malloc(m*n*sizeof(struct Node));
    int front = 0;
    int rear = 0;
    queue[rear].r = sr;
    queue[rear].c = sc;
    rear++;

    

    int** vis = malloc(m*sizeof(int*));
    for(int i=0; i<m; i++){
        vis[i] = calloc(n, sizeof(int));
    }

    vis[sr][sc]=1;
    
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(front<rear){
        int row = queue[front].r;
        int col = queue[front].c;
        front++;

        

        for(int i=0; i<4; i++){
            int nRow = delRow[i]+row;
            int nCol = delCol[i]+col;

            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol] && image[nRow][nCol]==oldColor){
                queue[rear].r = nRow;
                queue[rear].c = nCol;
                rear++;

                vis[nRow][nCol] = 1;
                image[nRow][nCol] = color;
            }
        }
    }

    for(int i=0; i<m; i++){
        free(vis[i]);
    }
    free(vis);
    free(queue);
    return image;

}