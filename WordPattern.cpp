class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;
        std::stringstream ss(s);
        std::string word;
        int i{}; 
        while (ss >> word) 
        {
            if (i == pattern.size()) 
            {
                return false; 
            }
            char currentChar = pattern[i];
            if (!charToWord.contains(currentChar) && 
                !wordToChar.contains(word)) 
            {
                charToWord[currentChar] = word;
                wordToChar[word] = currentChar;
            } 
            else 
            {
                if (charToWord[currentChar] != word || wordToChar[word] != currentChar) 
                {
                    return false; 
                }
            }
            ++i; 
        }
        return i == pattern.size(); 
    }
};