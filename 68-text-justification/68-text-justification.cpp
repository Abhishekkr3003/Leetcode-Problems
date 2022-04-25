/* 
    Time: O(n)
    Space: O(n)
    Tag: String, Math
    Difficulty: MH
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        string cur = "";
        int left_ = maxWidth;
        int wordsInLine = 0;
        int start = 0;
        for (int i = 0; i < words.size(); i++) {
            // cout << i << " " << left_ - 1 << " " << words[i].length() << endl;
            // cout << ((words[i].length()) <= (left_ - 1)) << endl;
            if ((wordsInLine != 0) && (words[i].length()+1 <= (left_))) {
                // cout << "In If\n";
                wordsInLine++;
                left_ -= words[i].length() + 1;
            } else if (wordsInLine == 0 && words[i].length() <= left_) {
                wordsInLine++;
                left_ -= words[i].length();
            } else {
                if (wordsInLine == 1) {
                    cur = words[start];
                    for (int j = words[start].length(); j < maxWidth; j++) {
                        cur += " ";
                    }
                } else {
                    // cout << "here\n";
                    int eqSpacesSize = (left_ + wordsInLine - 1) / (wordsInLine - 1);
                    int extraSpacesCount = (left_ + wordsInLine - 1) % (wordsInLine - 1);

                    string equalSpace = "";
                    for (int j = 0; j < eqSpacesSize; j++) {
                        equalSpace += " ";
                    }
                    for (int j = start; j < i - 1; j++) {
                        cur += words[j] + equalSpace;
                        if (extraSpacesCount) {
                            extraSpacesCount--;
                            cur += " ";
                        }
                    }
                    cur += words[i - 1];
                }
                // cout << cur << endl;
                res.push_back(cur);
                cur = "";
                start = i;
                wordsInLine = 0;
                i--;
                left_ = maxWidth;
            }
        }

        for (int j = start; j < words.size() - 1; j++) {
            cur += words[j] + " ";
        }
        cur += words.back();
        while (cur.length() < maxWidth) cur += " ";
        res.push_back(cur);
        return res;
    }
};