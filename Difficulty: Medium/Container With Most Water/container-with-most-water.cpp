//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int ans=0;
        int s=0,e=arr.size()-1;
        while(e>s){
            int temp=min(arr[s],arr[e]);
            int v=temp*(e-s);
            ans=max(ans,v);
            if(arr[s]>arr[e]){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends