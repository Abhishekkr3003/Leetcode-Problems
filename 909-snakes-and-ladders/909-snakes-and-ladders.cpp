/*
    Time: O(n^2)
    Space: O(n^2)
    Tag: BFS
    Difficulty: E
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if(n==1) return 0;
        for (int i = 0;i < n / 2;i++) {
            swap(board[i], board[n - i - 1]);
        }
        for (int i = 1; i < n; i += 2) {
            reverse(board[i].begin(), board[i].end());
        }
        queue<int>q;
        q.push(0);
        int dist = -1;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int j = 0; j < size; j++) {
                int curr = q.front();
                q.pop();
                if (curr == (n * n) - 1) return dist;
                for (int i = 1; i <= 6; i++) {
                    if (curr + i < n * n) {
                        int x = (curr + i) / n;
                        int y = (curr + i) % n;
                        if (board[x][y] != -2) {
                            if (board[x][y] == -1) q.push(curr + i);
                            else q.push(board[x][y]-1);
                            board[x][y] = -2;
                        }
                    }
                }

            }
        }
        return -1;
    }
};