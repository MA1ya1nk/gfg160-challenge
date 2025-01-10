//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        long long sum=0;
        int lar=0;
        unordered_map<long long,int> m;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum==k){
                int temp=i+1;
                lar=max(lar,temp);
            }
            long long rem=sum-k;
            if(m.find(rem) != m.end()){
                int temp=i-m[sum-k];
                lar=max(lar,temp);
            }
            if(m.find(sum) == m.end()){
            m[sum]=i;
            }
        }
        return lar;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends