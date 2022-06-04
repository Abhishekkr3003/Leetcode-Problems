class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        if(x%10==0) return false;
        int temp=0;
        while(x>temp){
            temp=(temp*10)+(x%10);
            x/=10;
        }
        // cout<<x<<" "<<temp;
        return (x==temp) || (x==temp/10);
    }
};