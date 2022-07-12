class Solution {
    
    bool canWe(vector<int>&ms, int idx, int curSum, int k, int &reqSum){
        if(curSum>reqSum) return false;
        if(idx==ms.size()){
            if(k==3) return (curSum==reqSum);
            else if(curSum==reqSum) return canWe(ms,0,0,k+1,reqSum);
            return false;
        }
        
        if(canWe(ms,idx+1,curSum,k,reqSum)) return true;
        if(ms[idx]!=-1){
            int oldNum=ms[idx];
            ms[idx]=-1;
            if(canWe(ms,idx+1,curSum+oldNum,k,reqSum)) return true;
            ms[idx]=oldNum;
        }
        return false;
    }
    
public:
    bool makesquare(vector<int>& ms) {
        int sum=accumulate(ms.begin(),ms.end(),0);
        if(sum%4!=0) return false;
        sum/=4;
        
        return canWe(ms,0,0,1,sum);
    }
};