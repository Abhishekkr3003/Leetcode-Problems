class Solution {
public:
    int countValidWords(string sentence) {
        stringstream s(sentence);
        
        string temp;
        
        int res=0;
        bool possible;
        
        while(getline(s,temp,' ')){
            // cout<<temp<<endl;
            possible=true;
            if(temp.empty()) continue;
            int hypCount=0;
            if(temp[0]=='-' || temp.back()=='-' || (temp.length()>1 && (temp[0]==',' || temp[0]=='.' || temp[0]=='!'))) continue;
            for(int i=0;i<temp.length()-1;i++){
                if(isdigit(temp[i]) || temp[i]==',' || temp[i]=='.' || temp[i]=='!'){
                    possible=false;
                    break;
                }
                if(temp[i]=='-') {
                    if(!isalpha(temp[i-1]) || !isalpha(temp[i+1])) {
                        possible=false;
                        break;
                    }
                    hypCount++;
                }
            }
            if(temp.back()=='-') hypCount++;
            if(isdigit(temp.back())) continue;
            if(possible && hypCount<2) res++;
            // cout<<res<<endl;
        }
        return res;
    }
};