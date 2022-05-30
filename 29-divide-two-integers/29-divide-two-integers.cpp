class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool sign=true;
        if(dividend<0 && divisor<0 || dividend>0 && divisor>0){
            sign=false;
        }
        if(divisor==INT_MIN){ 
            int temp=(dividend==INT_MIN);
            if(temp) return (sign?-1:1);
            return 0;
        } 
        if(divisor==-1 && dividend==INT_MIN) {
            if(sign) return INT_MIN;
            return INT_MAX;
        }
        bool intMin=false;
        if(dividend==INT_MIN) {
            intMin=true;
            dividend=abs(dividend+abs(divisor));
        }
        else dividend=abs(dividend);
        divisor=abs(divisor);
        
        
        // cout<<dividend<<" "<<divisor<<endl;
        int res=0;
        int shift=0;
        while(dividend>=divisor){
            shift=0;
            while((divisor)<=(dividend>>shift)){
                shift++;
            }
            shift--;
            res+=(1<<shift);
            dividend-=(divisor<<shift);
        }
        if(intMin) return (sign?(-res)-1:res+1);
        return (sign?-res:res);
    }
};