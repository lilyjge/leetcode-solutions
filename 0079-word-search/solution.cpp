typedef pair<int, int> pi;

class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string word;
    int rows, cols;
    vector<vector<char>> board;
    bool exist(vector<vector<char>>& b, string w) {
        word = w;
        board = b;
        rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '0';
                    if (dfs(i, j, 0)) return true;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }

    bool dfs(int r, int c, int index) {
        index++;
        if (index == word.length()) return true;
        for(int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '0' && board[nr][nc] == word[index]) {
                char temp = board[nr][nc];
                board[nr][nc] = '0';
                if (dfs(nr, nc, index)) return true;
                board[nr][nc] = temp;
            }
        }
        return false;
    }
};
