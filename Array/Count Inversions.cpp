//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.k
    long long merge(long long arr[], long long left, long long mid, long long right){
        long long n1 = mid-left+1 , n2 = right-mid;
        long long a[n1] , b[n2];
        for(long long i=0; i<n1; i++){
            a[i] = arr[left+i];
        }
        for(long long i=0; i<n2; i++){
            b[i] = arr[mid+i+1];
        }
        long long i =0,j=0,k=left,count =0;
        while(i<n1 and j<n2){
            if(a[i] <= b[j]){
                arr[k++] = a[i++];
            }
            else{
                arr[k++] = b[j++];
                count += (n1-i);
            }
        }
        while(i < n1){
            arr[k++] = a[i++];
        }
        while(j < n2){
            arr[k++] = b[j++];
        }
        return count;
    }
    long long mergeSort(long long arr[] , long long left, long long right){
        long long count =0;
        if(left >= right) return count;
        long long mid = (left+right)/2;
        count = count + mergeSort(arr,left, mid);
        count = count + mergeSort(arr,mid+1,right);
        count = count + merge(arr,left, mid,right);
        return count;
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        return mergeSort(arr,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends