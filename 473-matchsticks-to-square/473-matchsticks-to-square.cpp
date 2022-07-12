class Solution {
    // set<vector<int>>mp;
    
    bool canWe(vector<int>&ms, int idx, int sum1, int sum2, int sum3, int sum4, int &reqSum){
        
        // cout<<idx<<" "<<sum1<<" "<<sum2<<" "<<sum3<<endl;
        if(sum1>reqSum || sum2>reqSum || sum3>reqSum || sum4>reqSum) return false;
        
        if(idx>=ms.size()){
            return (sum1==reqSum && sum2==reqSum && sum3==reqSum && sum4==reqSum);
        }
         
        // vector<int> key={sum1,sum2,sum3,sum4};
        
        // if(mp.find(key)!=mp.end()) return false;
        
        if(canWe(ms,idx+1,sum1+ms[idx],sum2,sum3,sum4,reqSum)) return true;
        if(canWe(ms,idx+1,sum1,sum2+ms[idx],sum3,sum4,reqSum)) return true;
        if(canWe(ms,idx+1,sum1,sum2,sum3+ms[idx],sum4,reqSum)) return true;
        if(canWe(ms,idx+1,sum1,sum2,sum3,sum4+ms[idx],reqSum)) return true;
        
        // mp.insert(key);
        return false;
    }
    
public:
    bool makesquare(vector<int>& ms) {
        int sum=accumulate(ms.begin(),ms.end(),0);
        if(sum%4!=0) return false;
        sum/=4;
        sort(ms.rbegin(),ms.rend());
        return canWe(ms,0,0,0,0,0,sum);
    }
};