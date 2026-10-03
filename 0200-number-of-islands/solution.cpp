typedef pair<int, int> pi;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int cnt = 0;
        queue<pi> q;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                // cout << vis[r][c] << " " << grid[r][c] << endl;
                if(vis[r][c] || grid[r][c] == '0') continue;
                cnt++;
                q.push({r, c});
                vis[r][c] = true;
                while(!q.empty()) {
                    pi cur = q.front(); q.pop();
                    int cr = cur.first, cc = cur.second;
                    for(int i = 0; i < 4; i++) {
                        int nr = cr + dir[i][0], nc = cc + dir[i][1];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                            vis[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
