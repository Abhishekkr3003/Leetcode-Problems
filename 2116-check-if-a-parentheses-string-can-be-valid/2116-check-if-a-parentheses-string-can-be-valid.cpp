/* 
    Time: O(n)
    Space: O(1)
    Tag: Greedy
    Difficulty: MH
*/

class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.length();

        int openCount = 0;

        for (int i = 0; i < n; i++) {
            // cout<<i<<" "<<openCount<<endl;
            if (s[i] == '(')
                openCount++;
            else if (locked[i] == '0')
                openCount++;
            else {
                if (openCount == 0) return false;
                openCount--;
            }
        }
        
        // cout<<"here";
        int closeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')')
                closeCount++;
            else if (locked[i] == '0')
                closeCount++;
            else {
                if (closeCount == 0) return false;
                closeCount--;
            }
        }
        return ((n&1)==0);
    }
};