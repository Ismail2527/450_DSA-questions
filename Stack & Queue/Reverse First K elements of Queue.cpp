//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        if (k > q.size()) {
            return q;
        }

        stack<int> s;

        // Reverse the first k elements by using a stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Push the reversed elements back into the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Move the remaining elements (which are in the correct order) to the back
        int remaining = q.size() - k;
        for (int i = 0; i < remaining; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends