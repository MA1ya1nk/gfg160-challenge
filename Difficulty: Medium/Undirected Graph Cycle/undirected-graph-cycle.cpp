//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int>q;
        for(int i=0;i<adj.size();i++){
        if(!visited[i]){
             q.push(i);
        visited[i]=true;
        parent[i]=-1;
        while(!q.empty()){
            int fr=q.front();
            q.pop();
            for(auto j:adj[fr]){
                if(visited[j] && j!=parent[fr]){
                    return true;
                }
                if(!visited[j]){
                    q.push(j);
                    visited[j]=true;
                    parent[j]=fr;
                }
            }
            
        }
        }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends