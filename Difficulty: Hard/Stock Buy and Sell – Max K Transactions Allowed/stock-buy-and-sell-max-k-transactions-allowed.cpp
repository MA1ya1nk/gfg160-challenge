//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==prices.size())
        return 0;
        if(k==0)
        return 0;
        if(dp[i][buy][k] != -1)
        return dp[i][buy][k];
        
        int profit=0;
        if(buy){
            int take=-prices[i]+solve(i+1,0,k,prices,dp);
            int leave=0+solve(i+1,1,k,prices,dp);
            profit=max(take,leave);
        }
        else{
            int take=prices[i]+solve(i+1,1,k-1,prices,dp);
            int leave=0+solve(i+1,0,k,prices,dp);
            profit=max(take,leave);
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends