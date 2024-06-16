class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int check = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            total = total + gas[i] - cost[i];
            check = check + gas[i] - cost[i];
            if(check < 0)
            {
                check = 0;
                ans = i + 1;
            }
        }
        if(total < 0)
        {
            return -1;
        }
        else 
        {
            return ans;
        }
    }
};