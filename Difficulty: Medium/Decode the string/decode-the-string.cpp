//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']') st.push(s[i]);
            else{
                string word;
                while(!st.empty() && st.top()!='['){
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(),word.end());//ishan
                st.pop();
                string k;
                while(!st.empty() && isdigit(st.top())){
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(),k.end());
                int num=stoi(k);//3
                string repeated;
                for(int j=0;j<num;j++){
                    repeated.append(word);//ishanishanishan
                }
                for(char c: repeated) st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends