class WordDictionary {
public:
    WordDictionary() {
        
    }
    void addWord(string word) {
        wordsSet.insert(word);
    }
    bool search(string word) {
        for(const string& savedWord : wordsSet){
            if(savedWord.length() != word.length()) continue;
            bool wordsMatch = true;
            for(int i = 0; i < word.length(); i++){
                if(word[i] != '.' && savedWord[i] != word[i]) {
                    wordsMatch = false;
                    break;
                }
            }
            if(wordsMatch) return true;
        }
        return false;
    }
private:
    unordered_set<string> wordsSet;
};