class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int count = 2;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int tp = 2;
                for(int k = 0; k < n; k++){
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if(((y2 - y1) * (x3 - x1)) == ((y3 - y1) * (x2 - x1)) && (k != i) && (k != j)){
                        tp++;
                    }
                }
                count = max(tp, count);
            }
        }
        return count;
    }
};