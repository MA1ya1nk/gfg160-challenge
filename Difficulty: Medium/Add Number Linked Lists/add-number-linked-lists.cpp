//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node* reverseList(Node* head) {
        Node* tmpHead = nullptr;

        while (head != nullptr) {
            Node* nex = head->next;
            if (tmpHead == nullptr) {
                tmpHead = head;
                tmpHead->next = nullptr;
            } else {
                head->next = tmpHead;
                tmpHead = head;
            }
            head = nex;
        }

        return tmpHead;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
         Node* l1 = reverseList(num1);
        Node* l2 = reverseList(num2);
        Node* curr = nullptr;
        int carry = 0;

        // Add numbers represented by the two linked lists
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int v1 = (l1 != nullptr) ? l1->data : 0;
            int v2 = (l2 != nullptr) ? l2->data : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            Node* tmp = new Node(sum % 10);
            tmp->next = curr;
            curr = tmp;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // Remove leading zeros if any
        while (curr != nullptr && curr->data == 0) {
            curr = curr->next;
        }

        return curr;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends