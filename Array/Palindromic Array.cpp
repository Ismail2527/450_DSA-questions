//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
  bool check(int data){
     int temp = data;
     int ans =0;
     while(temp >0){
         int r = temp%10;
         temp = temp/10;
         ans = (ans*10)+r;
     }
     if(ans == data){
         return true;
     }
     return false;
  }
    bool PalinArray(vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size(); i++){
            if(check(arr[i]) == false){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends