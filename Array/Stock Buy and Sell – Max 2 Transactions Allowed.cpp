//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n = price.size();
        if (n < 2) return 0;

        // Store max profit up to each day from left and right
        int leftProfit = 0, rightProfit = 0;
        int minPrice = price[0], maxPrice = price[n-1];
        vector<int> left(n, 0), right(n, 0);

        // Left to right - max profit if sold by day i
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, price[i]);
            left[i] = max(left[i-1], price[i] - minPrice);
        }

        // Right to left - max profit if bought from day i
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, price[i]);
            right[i] = max(right[i+1], maxPrice - price[i]);
        }

        // Combine both
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
        }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends