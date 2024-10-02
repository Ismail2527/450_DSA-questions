//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>fact;
        fact.push_back(1);
        
        for(int i=2; i<=N; i++){
            int carry =0;
            for(int j=0; j<fact.size(); j++){
                int product = fact[j] * i;
                product = product + carry;
                carry = product / 10;
                fact[j] = product % 10;
            }
            if(carry){
                while(carry){
                    fact.push_back(carry%10);
                    carry = carry / 10 ;
                }
            }
        }
        reverse(fact.begin(),fact.end());
        return fact;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends