//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool allowed(vector<vector<int>> &mat,int row,int col,int val){
        for(int i=0;i<mat[0].size();i++){
            // for row
            if(mat[row][i]==val) return false;
            
            // for col
            if(mat[i][col]==val) return false;
            
            // for submat
            if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
            
        }
        return true;
    }
    bool solve(vector<vector<int>> &mat){
        int n=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    // inserting all values at vacant space
                    for(int val=1;val<=9;val++){
                        // checking condition of inserting value
                        if(allowed(mat,i,j,val)){
                            mat[i][j]=val;
                            // call for next vacant space
                            bool a=solve(mat);
                            if(a){
                                return true;
                            }
                            else{
                                // backtrack
                                mat[i][j]=0;
                            }
                            
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        bool ans=solve(mat);
        return ;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends