//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,int n,vector<int> &dp){
     if(i==n) return 1;
     if(i>n) return 0;
     if(dp[i]!=-1) return dp[i];
     
     dp[i]=solve(i+1,n,dp)+solve(i+2,n,dp);
     
     return dp[i];
  }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,-1);
        
        return solve(0,n,dp);
        
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends