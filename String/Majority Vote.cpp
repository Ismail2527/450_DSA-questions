//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
    if(n == 0) return {-1};

    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;

    // Step 1: Find candidates
    for(int num : arr) {
        if(num == candidate1) {
            count1++;
        } else if(num == candidate2) {
            count2++;
        } else if(count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if(count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify candidates
    count1 = 0;
    count2 = 0;
    for(int num : arr) {
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
    }

    vector<int> result;
    if(count1 > n / 3) result.push_back(candidate1);
    if(count2 > n / 3) result.push_back(candidate2);

    return result.empty() ? vector<int>{-1} : result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends