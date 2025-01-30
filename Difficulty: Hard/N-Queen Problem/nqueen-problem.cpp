//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void createans(vector<vector<int>> & board,vector<vector<int>> &ans,int n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[j][i]){
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }
    bool issafe(vector<vector<int>> &board,int col,int i,int n){
        int x=i;
        int y=col;
        // checking for same column
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        
        x=i;
        y=col;
        // checking for up diagonal
        while(x>=0 && y>=0){
            if(board[x][y]==1) return false;
            x--;
            y--;
        }
        
        x=i;
        y=col;
        // checking for down diagonal
        while(x<n && y>=0){
            if(board[x][y]==1) return false;
            x++;
            y--;
        }
        
        return true;
    }
    void solve(int col,vector<vector<int>> & board,vector<vector<int>> &ans,int n){
        if(col == n){
            // inserting answer
            createans(board,ans,n);
            return ;
        }
        
        for(int i=0;i<n;i++){
            if(issafe(board,col,i,n)){
                // inserting queen
                board[i][col]=1;
                solve(col+1,board,ans,n);
                //backtrack
                board[i][col]=0;
            }
        }
        
        
    }
    vector<vector<int>> nQueen(int n) {
        //creating board
       vector<vector<int>> board(n,vector<int>(n,0));
       vector<vector<int>> ans;
       solve(0,board,ans,n);
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends