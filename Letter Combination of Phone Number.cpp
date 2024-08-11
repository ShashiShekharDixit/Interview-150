class Solution {
public:
    void backtraking(map<char, string> &digitToChar, vector<string> &res, int i, string digits, string curStr)
    {
        if(curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        for(auto &c:digitToChar[digits[i]]) backtraking(digitToChar, res, i + 1, digits, curStr + c);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, string> digitToChar = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.size())
        backtraking(digitToChar, res, 0, digits,"");
        return res;
    }
};