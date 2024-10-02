//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int>neg;
        vector<int>pos;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<0){
                neg.push_back(arr[i]);
            }
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
        }
        int k=0; 
        while(k<pos.size()){
            arr[k] = pos[k];
            k++;
        }
        int g=0;
        while(k<arr.size()){
            arr[k] = neg[g];
            k++;
            g++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends