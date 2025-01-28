//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void removeduplicate(vector<string> &ans){
      unordered_map<string,int>pre;
      for(int i=0;i<ans.size();i++){
          pre[ans[i]]++;
      }
      ans.clear();
      for(auto i:pre){
          ans.push_back(i.first);
      }
  }
    void solve(string s,vector<string>& ans,int count){
        if(count>=s.size()){
            ans.push_back(s);
            return  ;
        }
        
        for(int i=count;i<s.size();i++){
            swap(s[i],s[count]);
            solve(s,ans,count+1);
            swap(s[i],s[count]);
        }
        
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        int count=0;
        solve(s,ans,count);
        removeduplicate(ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends