/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<char> sec(10, 0), gue(10, 0);
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i])
                bull++;
            else {
                sec[secret[i] - '0']++;
                gue[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cow += min(sec[i], gue[i]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};