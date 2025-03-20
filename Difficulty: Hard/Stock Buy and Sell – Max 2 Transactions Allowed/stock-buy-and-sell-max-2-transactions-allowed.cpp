//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int buy,int limit,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==prices.size())
        return 0;
        if(limit==0)
        return 0;
        if(dp[i][buy][limit] != -1)
        return dp[i][buy][limit];
        
        int profit=0;
        if(buy){
            int take=-prices[i]+solve(i+1,0,limit,prices,dp);
            int leave=0+solve(i+1,1,limit,prices,dp);
            profit=max(take,leave);
        }
        else{
            int sell=prices[i]+solve(i+1,1,limit-1,prices,dp);
            int notSell=0+solve(i+1,0,limit,prices,dp);
            profit=max(sell,notSell);
        }
        
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends