
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Time: O(n^2)
    Space: O(n^2)
    Tag: DFS
    Difficulty: M
*/

class Solution {
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, bool& flag) {
        visited[i][j] = true;
        for (auto move : moves) {
            if (i + move.first >= 0 && i + move.first < board.size() && j >= 0 && j + move.second < board[0].size()) {
                int newX = i + move.first;
                int newY = j + move.second;
                if (!visited[newX][newY] && board[newX][newY] == 'O') {
                    dfs(board, newX, newY, visited, flag);
                }
            }
        }
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) flag = true;
    }

    void changeToX(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'X';
        for (auto move : moves) {
            if (i + move.first >= 0 && i + move.first < board.size() && j >= 0 && j + move.second < board[0].size()) {
                int newX = i + move.first;
                int newY = j + move.second;
                if (board[newX][newY] == 'O') {
                    changeToX(board, newX, newY);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                bool flag = false;
                if (!visited[i][j] && board[i][j] == 'O') {
                    // cout << i << j << endl;
                    dfs(board, i, j, visited, flag);
                    if (!flag) {
                        // cout << "here";
                        changeToX(board, i, j);
                    }
                }
            }
        }
    }
};