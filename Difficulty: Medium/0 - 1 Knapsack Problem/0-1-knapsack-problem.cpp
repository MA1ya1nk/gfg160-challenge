//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int ind,int wtt,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
      //base case
      if(ind==0){
          if(wt[0]<=wtt)
          return val[0];
          else
          return 0;
      }
      if(dp[ind][wtt] != -1)
      return dp[ind][wtt];
      
      int include=0;
      if(wt[ind]<=wtt)
      include=solve(ind-1,wtt-wt[ind],val,wt,dp)+val[ind];
      int exclude=solve(ind-1,wtt,val,wt,dp)+0;
      
      return dp[ind][wtt]=max(include,exclude);
      
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(val.size(),vector<int>(W+1,-1));
        return solve(val.size()-1,W,val,wt,dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends