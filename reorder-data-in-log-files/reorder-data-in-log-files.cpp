class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>dig;
        vector<string>let;
        string temp;
        for(string s:logs){
            if(isalpha(s.back())){
                let.push_back(s);
            }else{
                dig.push_back(s);
            }
        }
        sort(let.begin(), let.end(),[](string a,string b){
            int i=0, j=0;
            while(!isspace(a[i++]));
            while(!isspace(b[j++]));
            string temp1=a.substr(i,a.length()-i);
            string temp2=b.substr(j,b.length()-j);
            if(temp1!=temp2) return temp1<temp2;
            else return a<b;
        });
        vector<string>res;
        for(string s:let) res.push_back(s);
        for(string s:dig) res.push_back(s);
        return res;
    }
};