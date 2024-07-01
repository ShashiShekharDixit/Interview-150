class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty() || words[0].empty()) {
            return result;
        }
        int wordLength = words[0].length();
        int numWords = words.size();
        int substringLength = wordLength * numWords;
        unordered_map<string, int> wordsCount;
        for(const string& word : words) {
            wordsCount[word]++;
        }
        for(int i = 0; i < wordLength; i++){
            unordered_map<string, int> seenWords;
            int left = i;
            int count = 0;
            for(int j = i; j <= static_cast<int>(s.length()) - wordLength; j += wordLength) {
                string word = s.substr(j, wordLength);
                if(wordsCount.find(word) != wordsCount.end()){
                    seenWords[word]++;
                    count++;
                    while(seenWords[word] > wordsCount[word]){
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    if(count == numWords){
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        return result;
    }
};