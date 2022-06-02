class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        vector<string>degree={"","Thousand","Million","Billion"};
        vector<string>unit={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string>tens={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string res="";
        
        for(int i=0;i<=3 && num;i++){
            string cur="";
            int bitCount=0;
            int lastBit=num%10;
            num/=10;
            int secLastBit=num%10;
            num/=10;
            int thirdLast=num%10;
            num/=10;
            if(secLastBit==1){
                cur=unit[secLastBit*10+lastBit];
                if(thirdLast!=0){
                    cur=unit[thirdLast]+" Hundred"+" "+cur;
                }
                if(!cur.empty() && cur.back()==' ') cur.pop_back();
                if(cur!="")
                    res=cur+" "+degree[i]+" "+res;
                continue;
            }
            if(thirdLast!=0) cur=unit[thirdLast]+" Hundred ";
            if(secLastBit!=0) cur+=tens[secLastBit]+" ";
            if(lastBit!=0) cur+=unit[lastBit];
            if(!cur.empty() && cur.back()==' ') cur.pop_back();
            if(cur!="") res=cur+" "+degree[i]+" "+res;
        }
        while(!res.empty() && res.back()==' ') res.pop_back();
        return res;
    }
};