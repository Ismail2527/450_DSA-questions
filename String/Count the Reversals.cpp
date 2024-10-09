//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int n = s.size();
    int o=0,c=0;
    int ans =0;
    if(n%2 ==0){
        for(int i=0; i<n; i++){
            if(s[i] == '{'){
                o++;
            }else{
                if(o == 0){
                    c++;
                }else{
                    o--;
                }
            }
            ans =static_cast<int>(ceil(o/2.0) + ceil(c/2.0));
        }
    }else{
        return -1;
    }
    return ans;
}