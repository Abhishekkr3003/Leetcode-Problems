56ms
```
class Solution {
bool dp[20][20];
vector<string> curList;
int n;
public:
vector<vector<string>> partition(string s) {
vector<vector<string>> ans;
n = s.length();
memset(dp, false, sizeof dp);
dfs(ans, s, 0);
return ans;
}
void dfs(vector<vector<string>> &ans, string &s, int start) {
if (start >= n) {
ans.emplace_back(curList);
}
for (int i = start; i < n; i++) {
if (s[start] == s[i] && (i - start <= 2 || dp[start + 1][i - 1])) {
dp[start][i] = true;
curList.emplace_back(s.substr(start, i - start + 1));
dfs(ans, s, i + 1);
curList.pop_back();
}
}
}
};
```