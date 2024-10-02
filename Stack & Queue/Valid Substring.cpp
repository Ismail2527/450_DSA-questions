//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string x) {
        // code here
        stack<int> st;
        int maxLen = 0;
        st.push(-1);  // Initialize stack with base index for length calculation
        
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '(') {
                st.push(i);  // Push the index of '('
            } else {
                st.pop();  // Pop the last unmatched '(' or base index
                
                if (!st.empty()) {
                    // Calculate the length of the current valid substring
                    maxLen = max(maxLen, i - st.top());
                } else {
                    // Push the index of unmatched ')'
                    st.push(i);
                }
            }
        }
        return maxLen;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends