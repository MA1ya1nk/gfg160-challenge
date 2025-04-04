//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int i,unordered_map<int,bool>& vis,unordered_map<int,int>& par,unordered_map<int,list<int>>& adj){
        
        for(auto j:adj[i]){
            if(!vis[j]){
                par[j]=i;
                vis[j]=1;
                bool ans=solve(j,vis,par,adj);
                if(ans) return true;
            }
            else if(vis[j] && par[i] != j){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int fir=edges[i][0];
            int sec=edges[i][1];
            adj[fir].push_back(sec);
            adj[sec].push_back(fir);
        }
        bool ans=false;
        unordered_map<int,bool> vis;
        
        unordered_map<int,int> par;
        for(int i=0;i<V;i++){
            if(!vis[i]){
            vis[i]=1;
            par[i]=-1;
            ans=solve(i,vis,par,adj);
            if(ans) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends