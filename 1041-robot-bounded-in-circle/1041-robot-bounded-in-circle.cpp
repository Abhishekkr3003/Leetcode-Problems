class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir=0;
        int x=0,y=0;
        for(char ch:instructions){
            if(ch=='L') dir=(dir+1)%4;
            else if(ch=='R') dir=(dir-1+4)%4;
            else {
                if(dir==0) y+=1;
                else if(dir==1) x-=1;
                else if(dir==2) y-=1;
                else x+=1;
            }            
        }
        // cout<<x<<y;
        return (x==0 && y==0) || dir!=0;
       
    }
};