/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<vector<vector<int>>> t;
    vector<int> solve(vector<string> &tokens, int lo, int hi) {
        if (lo == hi) return {stoi(tokens[lo])};
        // if (!t[lo][hi].empty()) return t[lo][hi];
        vector<int> ans;
        for (int i = lo; i <= hi; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*") {
                vector<int> left = solve(tokens, lo, i - 1);
                vector<int> right = solve(tokens, i + 1, hi);
                if (left.size() == 0 || right.size() == 0) continue;
                for (int num : left) {
                    for (int num1 : right) {
                        if (tokens[i] == "+")
                            ans.push_back(num + num1);
                        else if (tokens[i] == "-")
                            ans.push_back(num - num1);
                        else
                            ans.push_back(num * num1);
                    }
                }
            }
        }
        return t[lo][hi]=ans;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<string> tokens;
        tokens.reserve(expression.length());
        int start = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (!isdigit(expression[i])) {
                tokens.push_back(expression.substr(start, i - start));
                tokens.push_back(expression.substr(i, 1));
                start = i + 1;
            }
        }
        tokens.push_back(expression.substr(start, expression.length() - start));
        t.resize(tokens.size() + 1, vector<vector<int>>(tokens.size() + 1));
        return solve(tokens, 0, tokens.size() - 1);
    }
};