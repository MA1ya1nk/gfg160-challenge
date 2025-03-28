//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>temp;
        for(int i=0;i<start.size();i++)temp.push_back({start[i],finish[i]});
        auto comp=[&](auto &a,auto& b){
            return a.second<b.second;
        };
        sort(temp.begin(),temp.end(),comp);
        int count=1;
        int currFinish=temp[0].second;
        for(int i=1;i<start.size();i++){
            if(temp[i].first>currFinish){
                count++;
                currFinish=temp[i].second;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends