//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
         // Your code here
        stack<char> st;
        for (int i = 0; i < x.size(); i++) {
            // Push opening brackets onto the stack
            if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
                st.push(x[i]);
            }
            // Check for matching closing brackets
            else if (x[i] == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            } else if (x[i] == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            } else if (x[i] == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            // If there's no match, the brackets are not balanced
            else {
                return false;
            }
        }
        // If the stack is empty, all brackets were balanced
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends