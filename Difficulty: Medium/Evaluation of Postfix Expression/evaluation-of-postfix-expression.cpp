//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
     stack<int>st;
     for(int i=0;i<arr.size();i++){
         string ch=arr[i];
         if(ch=="+" || ch=="-" || ch== "*" || ch=="/" ){
             int num1=st.top();
             st.pop();
             int num2=st.top();
             st.pop();
             int result;
             if(ch=="+"){
                result=num1+num2; 
             }
             if(ch=="-"){
                result=num2-num1; 
             }
             if(ch=="*"){
                result=num1*num2; 
             }
             if(ch=="/"){
                result=num2/num1; 
             }
             st.push(result);
         }
         else{
             int num=stoi(ch);
             st.push(num);
         }
     }
     
     return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends