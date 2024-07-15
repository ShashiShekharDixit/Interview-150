class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> left, right;
        for(const auto& interval : intervals){
            int first = interval[0];
            int last = interval[1];
            if(last < start) {
                left.push_back(interval);
            } else if(first > end){
                right.push_back(interval);
            } else {
                start = min(start, first);
                end = max(end, last);
            }
        }
        left.push_back({start, end});
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};