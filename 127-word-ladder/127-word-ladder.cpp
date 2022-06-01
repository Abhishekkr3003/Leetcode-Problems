#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> notVisited(wordList.begin(), wordList.end());
        if (notVisited.find(endWord) == notVisited.end())
            return 0;
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        while (!q.empty()) {
            string word = q.front().second;
            int val = q.front().first;
            q.pop();
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (int j = 0; j < 26; j++) {
                    temp[i] = 'a' + j;
                    if (notVisited.find(temp) != notVisited.end()) {
                        q.push({val + 1, temp});
                        notVisited.erase(temp);
                        if (endWord == temp)
                            return val + 2;
                    }
                }
            }
        }
        return 0;
    }
};