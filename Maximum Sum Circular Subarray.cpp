class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int pos = kadane(nums, 1), neg = sum + kadane(nums, -1);
        if(neg > pos && neg == 0){
            for(int num : nums)
            if(num == 0)
            return 0;
            return pos;
        }
        return max(pos, neg);
    }
    int kadane(vector<int>& nums, int sign){
        int global, local;
        global = sign * nums[0];
        local = 0;
        for(int num : nums){
            local += sign * num;
            global = max(global, local);
            local = max(local, 0);
        }
        return global;
    }
};