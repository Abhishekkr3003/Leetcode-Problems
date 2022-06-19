class Solution {
    public int longestSubsequence(String str, int k) {
		 StringBuilder sb=new StringBuilder(str);
		 sb.reverse();
		 dp=new Long[sb.length()+5][sb.length()+5];
		 char[] s=sb.toString().toCharArray();
		 long ans = longestSeq(s, k, 0, 0);
		 return (int)ans;
		 
		 
	 }
	 Long[][] dp;
	long longestSeq(char[] s,int k,int i,int c) {
		 if(i>=s.length) {
			return 0;
		 }
		 if(dp[i][c]!=null) return dp[i][c];
		
		 
		 if(c<31 && k>=((s[i]-'0')*(1<<c))){   
			 long L1 =longestSeq(s, k-((s[i]-'0')*(1<<c)), i+1, c+1)+1;    // include 
			 long L2 =longestSeq(s, k, i+1, c)+0;   // exclude
			 return dp[i][c]=Math.max(L1, L2);
		 }else if(s[i]=='0'){
             long L1 =longestSeq(s, k, i+1, c+1)+1;    // include 
			 long L2 =longestSeq(s, k, i+1, c)+0;   // exclude
			 return dp[i][c]=Math.max(L1, L2);
         }else {
             long L2=longestSeq(s, k, i+1, c)+0;   // exclude
			 return dp[i][c]=L2;
		 }
		 
	 }
}