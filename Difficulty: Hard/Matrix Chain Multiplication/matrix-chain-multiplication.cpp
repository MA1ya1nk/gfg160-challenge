//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int start, int end,  vector<int>&arr, vector<vector<int>>&dp){
        if(end-start==1) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        
        int ans=INT_MAX;
        for(int k=start+1;k<end;k++){
            int left=helper(start, k, arr, dp);
            int right=helper(k, end, arr, dp);
            ans=min(ans, left+right+arr[start]*arr[k]*arr[end]);
        }
        return dp[start][end] = ans;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return helper(0, n-1, arr, dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends