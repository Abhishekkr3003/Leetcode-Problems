class Solution {
public:
    int addDigits(int num) {
        /* Sol1
        int temp=0;
        while(num>=10){
            temp=0;
            while(num>0){
                temp+=num%10;
                num/=10;
            }
            num=temp;
        }
        return num;
        */
        //Sol2
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};