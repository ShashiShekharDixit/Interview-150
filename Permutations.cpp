class Solution {
public:
        vector<vector<int>> ans;
        void backtrack(vector<int>& nums, vector<int> &v)
        {
            if(nums.empty())
            {
                ans.push_back(v);
                return;
            }
            for(int i =0; i < nums.size(); i++)
            {
                v.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                backtrack(nums,v);
                nums.insert(nums.begin()+i,v.back());
                v.pop_back();
            }
        }
        vector<vector<int>> permute(vector<int>& nums){
            vector<int> v;
            backtrack(nums,v);
            return ans;
        }
};