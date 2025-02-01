//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(vector<vector<char>>& mat,string& word ,int i,int j,int idx,vector<vector<bool>>&vis){
        //base case
        if(idx==word.length()) return true;
        
        if(i<0 || j<0 || i>= mat.size() || j>=mat[0].size() || vis[i][j] || mat[i][j]!=word[idx]) return false;
        //recursive case
        vis[i][j]=true;
        if(solve(mat,word,i-1,j,idx+1,vis) || solve(mat,word,i+1,j,idx+1,vis)
        || solve(mat,word,i,j-1,idx+1,vis) || solve(mat,word,i,j+1,idx+1,vis) ) return true;
        vis[i][j]=false;
        
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    if(solve(mat,word,i,j,0,vis)) return true;
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
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