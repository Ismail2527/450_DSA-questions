//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
#define N 1000
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          // Create a priority queue to store [value, arrayIndex, elementIndex]
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Initialize the queue with the first element from each array
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i < k; ++i) {
            pq.push({KSortedArray[i][0], {i, 0}});
            maxVal = std::max(maxVal, KSortedArray[i][0]);
        }

        pair<int, int> range = {pq.top().first, maxVal}; // Initialize range

        while (!pq.empty()) {
            // Get the element with the minimum value
            auto top = pq.top();
            pq.pop();

            minVal = top.first;
            int arrIndex = top.second.first;
            int elementIndex = top.second.second;

            // Update the range if the current window is smaller
            if (maxVal - minVal < range.second - range.first) {
                range = {minVal, maxVal};
            }

            // Check if there are more elements in the current array
            if (elementIndex + 1 < n) {
                int nextVal = KSortedArray[arrIndex][elementIndex + 1];
                pq.push({nextVal, {arrIndex, elementIndex + 1}});
                maxVal = std::max(maxVal, nextVal);  // Update the maxVal for the new element
            } else {
                break;  // If we have exhausted one list, we can't find a smaller range
            }
        }

        return range;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends