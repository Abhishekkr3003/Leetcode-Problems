class Solution {
    void solve(string digits,int index,vector<string>&res,vector<string>&phone, string curString){
        if(index==digits.size()){
            res.push_back(curString);
            return;
        } 
        for(char ch:phone[digits[index]-'0']){
            solve(digits,index+1,res,phone,curString+ch);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        vector<string>res;
        vector<string>phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,res,phone,"");
        return res;
    }
};