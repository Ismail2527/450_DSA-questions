class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        // Your code goes here
        long long int ans =0;
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            if(arr[i]<0&& k != 0){
                arr[i] = arr[i]*-1;
                k--;
            }
        }
        if(k != 0){
            sort(arr,arr+n);
            if(k > 0 && k%2 == 0){
                arr[0] = arr[0]*1;
                for(int i=0; i<n; i++){
                ans = ans + arr[i];
                }
            }else{
                arr[0] = arr[0]*-1;
                for(int i=0; i<n; i++){
                ans = ans + arr[i];
                }
            }
        }else{
            for(int i=0; i<n; i++){
                ans = ans + arr[i];
            }
        }
        return ans;
    }
};