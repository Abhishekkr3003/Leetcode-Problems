class Solution {
    
    bool compare(pair<string,string>&p1, pair<string,string>&p2){
        bool p1Digit=isdigit(p1.second.back());
        bool p2Digit=isdigit(p2.second.back());
        if(p1Digit && p2Digit) return false;
        else if(p1Digit) return true;
        else if(p2Digit) return false;
        if(p1.second==p2.second) return p1.first>p2.first;
        return p1.second>p2.second;        
    }
    
    void merge(int lo, int hi, int mid, vector<pair<string,string>>&logSep){
        vector<pair<string,string>>res(hi-lo+1);
        int i=lo, j=mid+1, k=0;
        while(i<=mid && j<=hi){
            if(compare(logSep[i],logSep[j])){
                res[k++]=logSep[j++];
            }else{
                res[k++]=logSep[i++];
            }
        }
        while(i<=mid){
            res[k++]=logSep[i++];
        }
        while(j<=hi){
            res[k++]=logSep[j++];
        }
        k=0;
        for(int i=lo;i<=hi;i++){
            logSep[i]=res[k++];
        }
    }
    
    void divideAndMerge(vector<pair<string,string>>&logSep, int lo, int hi){
        
        if(lo>=hi) return;
        int mid=lo+(hi-lo)/2;
        
        divideAndMerge(logSep,lo,mid);
        divideAndMerge(logSep,mid+1,hi);
        
        merge(lo,hi,mid, logSep);
        
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>>logSep(logs.size());
        
        for(int i=0;i<logs.size();i++){
            for(int j=0;j<logs[i].length();j++){
                if(logs[i][j]==' ') {
                    logSep[i]={logs[i].substr(0,j), logs[i].substr(j+1,logs[i].length()-j-1)};
                    break;
                }
            }
            
        }
        // for(auto temp:logSep){
        //     cout<<temp.first<<" "<<temp.second<<endl;
        // }
        divideAndMerge(logSep,0,logs.size()-1);
        for(int i=0;i<logs.size();i++){
            logs[i]=logSep[i].first+" "+logSep[i].second;
        }
        return logs;        
    }
};