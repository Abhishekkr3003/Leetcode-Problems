class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>>pth;
        unordered_map<string, int>count;
        vector<vector<string>> res;
        for(string s:paths){
            int i=0;
            string path="";

            while(s[i]!=' ')
                path+=s[i++];
            path+="/";

            i++;
            while(i<s.length()){
                string file="";
                while(s[i]!='(')
                    file+=s[i++];
                i++;
                string word="";
                while(s[i]!=')')
                    word+=s[i++];
                i+=2;
                //cout<<path<<" "<<word<<"\n";
                if(count.find(word)!=count.end()){
                    pth[word].push_back(path+file);
                    count[word]++;
                }
                else{
                    pth[word].push_back(path+file);
                    count[word]=1;
                }
            }
        
        }
        for(auto p: count){
            if(p.second>1){
                res.push_back(pth[p.first]);
            }
        }
        return res;
    }
};