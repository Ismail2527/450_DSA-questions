//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zc = 0;
        int oc = 0;
        int tc = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0){
                zc++;
            }else if(arr[i] == 1){
                oc++;
            }else{
                tc++;
            }
        }
        int j = 0;
        while(zc != 0){arr[j++] = 0;zc--;}
        while(oc != 0){arr[j++] = 1;oc--;}
        while(tc != 0){arr[j++] = 2;tc--;}
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends