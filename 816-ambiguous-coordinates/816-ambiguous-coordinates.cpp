/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
    vector<string>res;
    void solve(string& s, string cur, int index, bool comma, bool decimal, bool firstDigit, bool nonZero) {
        if (index == s.length() - 1) {
            // cout<<cur<<endl;
            // cout<<cur[cur.size()-2]<<endl;
            if(decimal && cur.back()=='0') return;
            if (cur.back() >= '0' && cur.back() <= '9' && comma && nonZero) {
                cur.push_back(')');
                res.push_back(cur);
            }
            return;
        }
        if (firstDigit && s[index] == '0') {
            if(index==s.length()-2) solve(s,cur+'0',index+1,true,false,false, true);
            if (!comma) solve(s, cur + "0, ", index + 1, true, false, true,false);
            if (!decimal) solve(s, cur + "0.", index + 1, comma, true, false,false);
            return;
        }
        if (s[index] == '0') nonZero = nonZero | 0;
        else nonZero = true;
        cur += s[index];
        solve(s, cur, index + 1, comma, decimal, false,nonZero);
        if (!decimal) {
            solve(s, cur + '.', index + 1, comma, true, false,false);
        }
        if (nonZero == false) return;
        if(decimal && cur.back()=='0') return;
        if (!comma) {
            solve(s, cur + ", ", index + 1, true, false, true,false);
        }
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        // if(s=="(00)") return {"(0, 0)"};
        solve(s, "(", 1, false, false, true,false);
        return res;
    }
};