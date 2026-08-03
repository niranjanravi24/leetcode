class Solution {
    void dfs(vector<vector<int>>& adjLs, vector<int>& vis, int node){
        vis[node]=1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(adjLs, vis, it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(adjLs, vis, i);
            }
        }
        return count;
    }
};