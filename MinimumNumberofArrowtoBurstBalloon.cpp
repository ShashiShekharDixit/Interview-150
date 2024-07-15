#define vec vector<int>
class Solution {
public:
    class cmp
    {
        public:
        bool operator()(vec &a, vec &b)
        {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        }
    };
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(), points.end(), cmp());
      int ans = 1, n = points.size();
      int start = points[0][0], end = points[0][1];
      for(int i = 0; i < n; i++)
      {
        vec balloon = points[i];
        if(balloon[0] > end)
        {
            ans++;
            start = balloon[0], end = balloon[1];
        }
        else {
            start = max(start, balloon[0]);
            end = min(end, balloon[1]);
        }
      }   
      return ans;
    }
};