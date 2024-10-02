class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0){
            return 0;
        }
        int mini = prices.at(0);
        int profit = 0;
        int maxi =0;
        for(int i=0; i<n; i++){
            mini = min(mini,prices.at(i));
            profit = prices.at(i) - mini;
            maxi = max(maxi,profit);
        }
        return maxi;
    }
};