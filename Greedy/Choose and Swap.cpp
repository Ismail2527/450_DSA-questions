//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string chooseandswap(string str) {
        // Code Here
        set<char>s;
        for(int i=0; i<str.size(); i++){ s.insert(str[i]);}
        for(int j=0; j<str.size(); j++){
            s.erase(str[j]);
            if(s.empty()) break;
            char ch = *s.begin();
            if(ch < str[j]){
                char ch2 = str[j];
                for(int k=0; k<str.size(); k++){
                    if(str[k] == ch){
                        str[k] = ch2;
                    }else if(str[k] == ch2){
                        str[k] = ch;
                    }
                }
                break;
            }
        }
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}

// } Driver Code Ends