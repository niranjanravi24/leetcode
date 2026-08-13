class Solution {
    int maxEle(vector<vector<int>>& mat, int mid){
        int m = mat.size();
        int n = mat[0].size();
        int maxVal = -1;
        int index = -1;
        for(int i=0; i<m; i++){
            if(mat[i][mid] > maxVal){
                maxVal = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = maxEle(mat,mid);
            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 < n ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};