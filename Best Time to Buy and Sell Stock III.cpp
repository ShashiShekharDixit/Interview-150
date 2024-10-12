class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int n = prices.size();
        int left[n], right[n];
        int leftmin = prices[0], rightmax = prices[n-1], maxprofit = 0;
        left[0] = 0; right[n - 1] = 0;                             
        int i,j;
        for(i = 1, j = n-2; i < n, j >= 0; i++, j--){
            leftmin  = min(leftmin, prices[i]);                   
            left[i]  = max(left[i - 1], prices[i] - leftmin);           
            rightmax = max(rightmax, prices[j]);                        
            right[j] = max(right[j + 1], rightmax - prices[j]);            
        }
        for(int i = 0; i < n; i++){
            maxprofit = max(maxprofit, left[i] + right[i]);
        }
        return maxprofit;
    }
};