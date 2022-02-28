class Solution {
    int getsum(int x)
    {
        int ans=0;
        while(x)
        {
           ans+=pow((x%10),2);
            x=x/10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
     bool visited[1001];
        memset(visited,false,sizeof(visited));
        int x=getsum(n);
        while(visited[x]==false)
        {
           visited[x]=true;
            x=getsum(x);
        }
        return visited[1];
    }
};