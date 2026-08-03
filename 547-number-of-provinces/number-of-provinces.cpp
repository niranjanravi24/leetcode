class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node){
        vis[node]=1;
        for(int nei=0; nei<isConnected.size(); nei++){
            if(isConnected[node][nei]==1 && !vis[nei]){
                dfs(isConnected, vis, nei);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(isConnected, vis, i);
            }
        }
        return count;
    }
};