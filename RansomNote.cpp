class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphabet(26,0);
        for(char c : ransomNote) {
            size_t i = magazine.find(c, alphabet[c - 'a']);
            if(i == string::npos) return false;
            alphabet[c - 'a'] = i + 1;
        }
        return true;
    }
};