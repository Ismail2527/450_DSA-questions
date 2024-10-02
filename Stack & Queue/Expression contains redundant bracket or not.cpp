//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(auto& ch : s){
            if(ch == ')'){
                char top = st.top();
                st.pop();
                bool flag = true;
                while(!st.empty() && top != '('){
                    if(top == '-'||top == '+'
                    ||top == '/'
                    ||top == '*'){
                        flag = false;
                    }
                    top = st.top();
                    st.pop();
                }
                if(flag == true){
                    return true;
                }
                
            }else{
                st.push(ch);
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends