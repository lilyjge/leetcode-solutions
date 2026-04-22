typedef pair<int, int> pi;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // flood fill + dis (priority q?)
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> q;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if (grid[r][c] != 2 || dis[r][c] == 0) continue;
                q.push({0, {r, c}});
                while(!q.empty()) {
                    auto e = q.top(); q.pop();
                    int d = e.first, cr = e.second.first, cc = e.second.second;
                    // cout << "cr " << cr << " cc " << cc << " d " << d << endl;
                    if (grid[cr][cc] == 2) {
                        dis[cr][cc] = 0;
                        d = 0;
                    } else if (dis[cr][cc] == -1 || dis[cr][cc] != -1 && d < dis[cr][cc]) {
                        dis[cr][cc] = d;
                    }
                    else continue;
                    // cout << "cr " << cr << " cc " << cc << " d " << dis[cr][cc] << endl;
                    for(int i = 0; i < 4; i++) {
                        int nr = cr + dir[i][0], nc = cc + dir[i][1];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                            grid[nr][nc] != 0 && dis[nr][nc] != 0) 
                            q.push({d + 1, {nr, nc}});
                    }
                }
            }
        }
        int mx = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if (grid[r][c] == 1 && dis[r][c] == -1)
                    return -1;
                else if (grid[r][c] == 1)
                    mx = max(mx, dis[r][c]);
            }
        }
        return mx;
    }
};
