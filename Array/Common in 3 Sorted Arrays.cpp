//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        unordered_map<int,bool>a1,a2,a3;
        for(int i=0; i<arr1.size(); i++){
            a1[arr1[i]] = true;
        }
        for(int i=0; i<arr2.size(); i++){
            a2[arr2[i]] = true;
        }
        for(int i=0; i<arr3.size(); i++){
            a3[arr3[i]] = true;
        }
        vector<int>ans;
        for(int i=0; i<arr1.size(); i++){
            if((a2.find(arr1[i]) != a2.end() && a2[arr1[i]] == true) 
            &&(a3.find(arr1[i]) != a3.end() && a3[arr1[i]] == true) 
            && a1[arr1[i]] == true){
                a1[arr1[i]] = false;
                a3[arr1[i]] = false;
                a2[arr1[i]] = false;
                
                ans.push_back(arr1[i]);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends