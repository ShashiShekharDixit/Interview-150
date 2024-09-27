class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minimum = INT_MAX;
        int rotate = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] < minimum){
                right = mid - 1;
                minimum = nums[mid];
                if(rotate == -1) rotate = mid;
            } else {
                left = mid + 1;
            }
            if(mid == 0 && nums[mid] == minimum){
                left = rotate + 1;
                right = nums.size() -1 ;
            }
        } 
        return minimum;
    }
};