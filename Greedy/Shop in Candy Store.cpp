//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
       sort(candies, candies + N);
        int minCost = 0, maxCost = 0;
        int minIndex = 0, maxIndex = N - 1;

        // Calculate minimum cost
        while (minIndex <= maxIndex) {
            minCost += candies[minIndex];
            minIndex++;
            maxIndex -= K;
        }

        // Reset indices for maximum cost calculation
        minIndex = 0;
        maxIndex = N - 1;

        // Calculate maximum cost
        while (maxIndex >= minIndex) {
            maxCost += candies[maxIndex];
            maxIndex--;
            minIndex += K;
        }

        // Return the results as a vector
        return {minCost, maxCost};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
       sort(candies, candies + N);
        int minCost = 0, maxCost = 0;
        int minIndex = 0, maxIndex = N - 1;

        // Calculate minimum cost
        while (minIndex <= maxIndex) {
            minCost += candies[minIndex];
            minIndex++;
            maxIndex -= K;
        }

        // Reset indices for maximum cost calculation
        minIndex = 0;
        maxIndex = N - 1;

        // Calculate maximum cost
        while (maxIndex >= minIndex) {
            maxCost += candies[maxIndex];
            maxIndex--;
            minIndex += K;
        }

        // Return the results as a vector
        return {minCost, maxCost};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends