class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int last = n - 1;
      for(int i = n - 2; i >= 0; i--){
        if(nums[i] >= (last - i)){
            last = i;
        }
      }  
      return (last <= 0);
    }
};