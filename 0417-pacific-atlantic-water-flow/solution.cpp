typedef pair<int, int> pi;
class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> atlantic; // 1 for can, 0 for not vis, -1 for cant, 2 for currently visiting
    vector<vector<int>> pacific;
    vector<vector<int>> h;
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        h = heights;
        atlantic.assign(m, vector<int>(n, 0)); 
        pacific.assign(m, vector<int>(n, 0));
        for(int r = 0; r < m; r++) {
            pacific[r][0] = 1;
            atlantic[r][n-1] = 1;
        }
        for(int c = 0; c < n; c++) {
            pacific[0][c] = 1;
            atlantic[m-1][c] = 1;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (dfs(i, j, true) == 1 && dfs(i, j, false) == 1)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    int dfs(int r, int c, bool p) {
        if (p && pacific[r][c]) return pacific[r][c];
        if (!p && atlantic[r][c]) return atlantic[r][c];
        if (p) pacific[r][c] = 2;
        else atlantic[r][c] = 2;
        // cout << r << ' ' << c << ' ' << p << endl;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && h[nr][nc] <= h[r][c]) {
                // cout << "nr nc " << nr << ' ' << nc << endl;
                if (p) {
                    if (pacific[nr][nc] == 1) {
                        pacific[r][c] = 1; break;
                    } else if (pacific[nr][nc] == 0) {
                        if (dfs(nr, nc, p) == 1) {
                            pacific[r][c] = 1; break;
                        }
                    }
                }
                else {
                    if (atlantic[nr][nc] == 1) {
                        atlantic[r][c] = 1; break;
                    } else if (atlantic[nr][nc] == 0) {
                        if (dfs(nr, nc, p) == 1) {
                            atlantic[r][c] = 1; break;
                        }
                    }
                }
            }
        }
        if (p && pacific[r][c] == 2) pacific[r][c] = 0;
        if (!p && atlantic[r][c] == 2) atlantic[r][c] = 0;
        // cout << r << ' ' << c << ' ' << pacific[r][c] << ' ' << atlantic[r][c] << endl;
        if (p) return pacific[r][c];
        return atlantic[r][c];
    }
};
