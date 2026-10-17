class Solution {
public:
    // int rows, cols;
    // int dir[2][2] = {{0, 1}, {1, 0}};
    // int ans = 0;
    int uniquePaths(int m, int n) {
        // n + m - 2 choose m - 1
        int a = max(m, n);
        int b = min(m, n);
        n = a + b - 2; m = b;
        double ans = 1.0;
        for(int i = 1; i <= m-1; i++) {
            ans *= ((double)n - (i-1));
            ans /= (double)i;
        }
        return (int)ans;
    }

    // void dfs(int r, int c, vector<vector<int>>& vis) {
    //     if (r == rows-1 && c == cols-1) {
    //         ans++; return;
    //     }
    //     for(int i = 0; i < 2; i++) {
    //         int nr = r + dir[i][0], nc = c + dir[i][1];
    //         if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc]) {
    //             vis[nr][nc] = 1;
    //             dfs(nr, nc, vis);
    //             vis[nr][nc] = 0;
    //         }
    //     }
    // }

};
