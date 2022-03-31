/*
    Time: O(1)
    Space: O(1)
    Tag: Strings
    Difficulty: M
*/

class Solution {
    string findEnglish(string s) {
        while (s.length() < 3) s = "0" + s;
        string res = "";
        vector<string>englishUpto19 = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        vector<string>englishOf10s = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        if (s[0] != '0') res = englishUpto19[s[0] - '0'] + " Hundred ";
        if (s[1] != '0') {
            if (s[1] == '1') {
                res += englishUpto19[(s[1] - '0') * 10 + (s[2] - '0')] + " ";
                return res;
            }
            else res += englishOf10s[s[1] - '0'] + " ";
        }
        if (s[2] != '0') res += englishUpto19[s[2] - '0'] + " ";
        return res;
    }
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string res = "";
        int round = 0;
        while (num) {
            int digit = 0;
            string lastThree = to_string(num % 1000);
            while (num && digit < 3) {
                num /= 10;
                digit++;
            }
            if (round == 0) {
                string ans=findEnglish(lastThree);
                if(ans!="") res=ans;
            }
            else if (round == 1) {
                string ans=findEnglish(lastThree);
                if(ans!="") res = ans + " Thousand " + res;
            }
            else if (round == 2) {
                string ans=findEnglish(lastThree);
                if(ans!="") res = ans + " Million " + res;
            }
            else {
                string ans=findEnglish(lastThree);
                if(ans!="") res = ans + " Billion " + res;
            }
            round++;
        }
        while(res.back()==' ') res.pop_back();
        int extra = 0;
        for (int i = 1; i < res.length(); i++) {
            if (res[i] == ' ' && res[i - 1] == ' ') extra++;
            else res[i - extra]=res[i];
        }
        while(extra--) res.pop_back();
        return res;
    }
};