//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.size();
        vector<int> last(26,-1);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        int ans=0,curr=-1;
        for(int i=0;i<n;i++){
            curr=max(curr,last[s[i]-'a']);
            if(curr==i){
                ans++;
                curr=-1;
            }
        }
        return ans;
    }
 };


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends