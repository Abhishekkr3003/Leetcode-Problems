/* 
    Time: O(n)
    Space: O(n)
    Tag: String Manipulation
    Difficulty: EM
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> rows(numRows);
        int rowNum = 0;
        bool inc = true;
        for (char ch : s) {
            rows[rowNum].push_back(ch);
            if (inc) {
                if (rowNum == numRows - 1) {
                    inc = false;
                    rowNum--;
                } else
                    rowNum++;
            } else {
                if (rowNum == 0) {
                    inc = true;
                    rowNum++;
                } else
                    rowNum--;
            }
        }
        string res = "";
        for (auto vec : rows) {
            for (char ch : vec) res += ch;
        }
        return res;
    }
};