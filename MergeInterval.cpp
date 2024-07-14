class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
      });
      vector<vector<int>> res;
      res.push_back({intervals[0][0], intervals[0][0]});
      int lastIdx = 0;
      for(const auto& interval : intervals){
        int s = interval[0];
        int e = interval[1];
        if(s <= res[lastIdx][1]) {
            if(e > res[lastIdx][1]) {
                res[lastIdx][1] = e;
            }
        }else {
            res.push_back({s, e});
            lastIdx++;
        }
      }
      return res;
    }
};