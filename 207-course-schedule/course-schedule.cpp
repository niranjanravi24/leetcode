class Solution {

    bool dfs(vector<vector<int>>& adjList,
             vector<int>& vis,
             vector<int>& pathVis,
             int node) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(int adjNode : adjList[node]) {

            if(!vis[adjNode]) {

                if(dfs(adjList, vis, pathVis, adjNode)) {
                    return true;
                }

            }
            else if(pathVis[adjNode]) {
                return true;
            }
        }

        pathVis[node] = 0;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjList(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {

                if(dfs(adjList, vis, pathVis, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};