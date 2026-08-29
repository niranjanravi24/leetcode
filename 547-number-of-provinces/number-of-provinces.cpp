class Solution {
    void dfs(vector<int>& vis, vector<vector<int>>& isConnected, int node){
        vis[node]=1;
        int size = isConnected.size();
        for(int nei=0; nei<size; nei++){
            if(isConnected[node][nei]==1 && !vis[nei]){
                vis[nei]=1;
                dfs(vis,isConnected,nei);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(vis,isConnected,i);
            }
        }
        return count;
    }
};