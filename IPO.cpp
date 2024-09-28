class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int currentProjectsCount = 0, n = profits.size(), totalCapital = w;
        vector<pair<int,int>> projects;
        for(int i = 0; i < n; i++) projects.push_back(make_pair(capital[i], profits[i]));
        sort(projects.begin(), projects.end());
        priority_queue<int> maximumCapital;
        int i = 0;
        while(currentProjectsCount < k){
            while(i < n && projects[i].first <= totalCapital){
                maximumCapital.push(projects[i].second);
                i++;
            }
            if(maximumCapital.empty()) break;
            totalCapital += maximumCapital.top();
            maximumCapital.pop();
            currentProjectsCount++;
        }
        return totalCapital;
    }
};