class Solution {
public:
    string intToRoman(int num) {
        vector<string>ones={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string>tens={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string>hundred={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>thoudand={"","M","MM","MMM"};
        
        string res="";
        for(int i=0;i<4;i++){
            int digit=num%10;
            num/=10;
            if(i==0){
                res=ones[digit]+res;
            }else if(i==1){
                res=tens[digit]+res;
            }else if(i==2){
                res=hundred[digit]+res;
            }else{
                res=thoudand[digit]+res;
            }
        }
        return res;
    }
};