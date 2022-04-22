/* 
    Time: O(n)
    Space: O(n)
    Tag: String
    Difficulty: E
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        bool broken[26] = {0};
        for (char &ch : brokenLetters) broken[ch - 'a'] = true;
        stringstream parser(text);
        string temp;
        while (getline(parser, temp, ' ')) {
            bool count = true;
            for (char &ch : temp) {
                if (broken[ch - 'a']) {
                    count = false;
                    break;
                }
            }
            if (count) res++;
        }
        return res;
    }
};