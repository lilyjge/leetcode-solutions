typedef pair<int, int> pi;
class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                queue<pi> st;
                queue<pi> q;
                q.push({i, j});
                st.push({i, j});
                dis[i][j] = 0;
                while(!q.empty()) {
                    auto e = q.front(); q.pop();
                    int r = e.first, c = e.second;
                    for(int k = 0; k < 4; k++) {
                        int nr = r + dir[k][0], nc = c + dir[k][1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] && dis[nr][nc] == -1) {
                            dis[nr][nc] = 0;
                            q.push({nr, nc});
                            st.push({nr, nc});
                        }
                    }
                }
                while(!st.empty()) {
                    auto e = st.front(); st.pop();
                    int r = e.first, c = e.second;
                    for(int k = 0; k < 4; k++) {
                        int nr = r + dir[k][0], nc = c + dir[k][1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && dis[nr][nc] == -1) {
                            if (grid[nr][nc]) {
                                return dis[r][c];
                            }
                            dis[nr][nc] = dis[r][c] + 1;
                            st.push({nr, nc});
                        }
                    }
                }
                break;
            }
        }
        return -1;
    }
};
