class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        // Create a min-heap (priority queue)
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Add all ropes to the min-heap
        for (long long i = 0; i < n; i++) {
            minHeap.push(arr[i]);
        }
        
        long long result = 0;
        
        // Iterate until we have only one rope left
        while (minHeap.size() > 1) {
            // Extract the two smallest ropes
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            
            // The cost of connecting them
            long long cost = first + second;
            result += cost;
            
            // Push the resulting rope back into the min-heap
            minHeap.push(cost);
        }
        
        return result;
    }
};