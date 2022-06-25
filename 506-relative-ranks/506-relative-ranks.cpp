class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>temp(score.begin(),score.end());
        sort(temp.rbegin(),temp.rend());
        
        unordered_map<int,int>pos;
        for(int i=0;i<temp.size();i++) pos[temp[i]]=i+1;
        vector<string>res(score.size());
        for(int i=0;i<score.size();i++){
            if(pos[score[i]]==1) res[i]="Gold Medal";
            else if(pos[score[i]]==2) res[i]="Silver Medal";
            else if(pos[score[i]]==3) res[i]="Bronze Medal";
            else res[i]=to_string(pos[score[i]]);
        }
        return res;   
    }
};