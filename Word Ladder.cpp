class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(beginWord) != st.end())
        st.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int shortestLevel = 0;
        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();
            if(word == endWord) {
                shortestLevel = level;
                break;
            }
            for(int i = 0; i < word.size(); i++){
                string str = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    str[i] = ch;
                    if(st.find(str) != st.end()) {
                        q.push({str, level + 1});
                        st.erase(str);
                    }
                }
            }
        }
        return shortestLevel;
    }
};