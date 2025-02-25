//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        stack<int> s;
    int max_area = 0; 
    int index = 0;

    while (index < arr.size()) {
        
        if (s.empty() || arr[index] >= arr[s.top()]) {
            s.push(index++);
        } else {
           
            int top_of_stack = s.top();
            s.pop();
            
            int area = arr[top_of_stack] * (s.empty() ? index : index - s.top() - 1);
            
            max_area = max(max_area, area);
        }
    }

    // Now pop the remaining bars from stack and calculate area
    while (!s.empty()) {
        int top_of_stack = s.top();
        s.pop();
        int area = arr[top_of_stack] * (s.empty() ? index : index - s.top() - 1);
        max_area = max(max_area, area);
    }

    return max_area;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends