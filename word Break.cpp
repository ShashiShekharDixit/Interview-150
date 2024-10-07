class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set, int start){
        if(start == s.size()){
            return true;
        }
        for(int i = start; i < s.size();  i++){
            if(set.count(s.substr(start, i + 1 - start)) &&wordBreak(s, set, i + 1)){
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, 0);
    }
};