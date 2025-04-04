//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int helper(int ind, int sum, vector<int>&coins, vector<vector<int>>&dp){
        if(sum==0) return 0;
        if(ind==coins.size()) return 1000001;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int take=INT_MAX;
        if(coins[ind]<=sum) take=1+helper(ind, sum-coins[ind], coins, dp);
        int not_take=helper(ind+1, sum, coins, dp);
        
        return dp[ind][sum] = min(take, not_take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        int ans=helper(0, sum, coins, dp);
        
        if(ans==1000001) return -1;
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends