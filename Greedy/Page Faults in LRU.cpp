//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        list<int> q; // Using list to emulate the contains functionality of Queue in Java
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            // Check if the page is not in the queue
            if (find(q.begin(), q.end(), pages[i]) == q.end()) {
                count++; // Page fault occurred
                q.push_back(pages[i]);
                // If queue size exceeds the capacity, remove the oldest page
                if (q.size() > C)
                    q.pop_front();
            } else {
                // If page is already in the queue, move it to the back (recently used)
                q.remove(pages[i]);
                q.push_back(pages[i]);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends