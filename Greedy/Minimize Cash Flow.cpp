//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // A utility function that returns index of minimum value in arr[]
    int getMinIndex(vector<int>& arr) {
        int minIndex = 0;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] < arr[minIndex])
                minIndex = i;
        return minIndex;
    }

    // A utility function that returns index of maximum value in arr[]
    int getMaxIndex(vector<int>& arr) {
        int maxIndex = 0;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        return maxIndex;
    }

    // A utility function to return minimum of 2 values
    int minOf2(int x, int y) {
        return (x < y) ? x : y;
    }

    // A function to settle the debts
    void settleDebts(vector<int>& amount, vector<vector<int>>& result, int n) {
        int maxCredit = getMaxIndex(amount);
        int maxDebit = getMinIndex(amount);

        // If all amounts are settled
        if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
            return;

        // Find the minimum of two amounts
        int min = minOf2(-amount[maxDebit], amount[maxCredit]);
        amount[maxCredit] -= min;
        amount[maxDebit] += min;

        // Store the transaction
        result[maxDebit][maxCredit] += min;

        // Recur for the remaining amounts
        settleDebts(amount, result, n);
    }
    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n) {
        // code here
        vector<int> amount(n, 0);

        // Calculate the net amount to be paid or received by each person
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                amount[i] += (transaction[j][i] - transaction[i][j]);

        // Initialize the result transaction matrix with 0
        vector<vector<int>> result(n, vector<int>(n, 0));

        // Settle the debts
        settleDebts(amount, result, n);

        return result;
    }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    }
    return 0;
}
// } Driver Code Ends