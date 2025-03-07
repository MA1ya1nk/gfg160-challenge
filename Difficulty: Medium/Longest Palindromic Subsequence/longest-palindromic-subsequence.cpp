//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   int dp[1001][1001];
    int LCS(string &a , string &b,int i,int j){
        //base case
        if(i==a.size() || j==b.size()) return 0;
        //recursive case
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i]==b[j]) return dp[i][j]= 1+LCS(a,b,i+1,j+1);
        else return dp[i][j]= max(LCS(a,b,i,j+1),LCS(a,b,i+1,j));
    }
    int longestPalinSubseq(string &s) {
        memset(dp,-1,sizeof(dp));
        string rev=s;
        reverse(rev.begin(),rev.end());
        return LCS(s,rev,0,0);
        
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends