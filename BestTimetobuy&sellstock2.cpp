class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int maxi = 0, profit = 0;
       int buy = prices[0];
       for(int i = 0; i < n; i++){
        if(prices[i] < buy){
            buy = prices[i];
        }
        else {
        profit = prices[i]-buy;
        buy = prices[i];
        maxi += profit;
        }
       } 
       return maxi;
    }
};