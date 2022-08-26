class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>digits;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        
        sort(digits.begin(), digits.end());
        long long num;
        if(digits[0]!=0) {
            num=0;
            for(int i=0;i<digits.size();i++){
                num=num*10+digits[i];
            }
            if((num&(num-1))==0) return true;
        }
        
        while(next_permutation(digits.begin(),digits.end())){
            if(digits[0]==0) continue;
            num=0;
            for(int i=0;i<digits.size();i++){
                num=num*10+digits[i];
            }
            if((num&(num-1))==0) return true;
        }
        return false;
    }
};