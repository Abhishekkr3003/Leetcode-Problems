# H | DP - Word Break and Fountain Type | T: O(n^2) | S: O(n^2)

class Solution:
    def minCut(self, s: str) -> int:
        def find_pal(i: int, j: int, t: dict, s: str) -> bool:
            if i >= j:
                return True
            if (i, j) in t:
                return t[(i, j)]
            if s[i]!=s[j]:
                t[(i, j)]= False
            else:
                t[(i, j)] = find_pal(i+1, j-1, t, s)
            return t[(i, j)]

        t = {}
        res = [2002 for i in range(len(s)+1)]
        res[0] = 0
        for i in range(len(s)):
            if res[i]==2002:
                continue
            for j in range(len(s)-1,i-1,-1):
                if find_pal(i,j,t,s):
                    res[j+1]=min(res[j+1],res[i]+1)
            
        return res[-1]-1