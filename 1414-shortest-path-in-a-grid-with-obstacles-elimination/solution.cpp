typedef pair<int, int> pi;

class Solution {
public:
    vector<vector<int>> grid;
    int rows, cols;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int shortestPath(vector<vector<int>>& g, int k) {
        // always try all directions you didn't come from
        // memoize visited ans and k remaining, if more k, overwrite
        // recursive, keep track of k left
        // base case: at corner, return steps
        // ran out of k and stuck
        rows = g.size(); cols = g[0].size();
        grid = g;
        vector<vector<int>> kleft(rows, vector<int>(cols, -1));
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        queue<pair<pi, pi>> q;
        q.push({{0, 0}, {0, k}});
        kleft[0][0] = k;
        ans[0][0] = 0;
        while(!q.empty()) {
            auto e = q.front(); q.pop();
            int r = e.first.first, c = e.first.second;
            int curans = e.second.first, kk = e.second.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && (ans[nr][nc] == -1 || kleft[nr][nc] < kk)) {
                    if (ans[nr][nc] == -1) ans[nr][nc] = curans + 1;
                    else ans[nr][nc] = min(ans[nr][nc], curans + 1);
                    if (grid[nr][nc] == 0) {
                        q.push({{nr, nc}, {curans + 1, kk}});
                        kleft[nr][nc] = kk;
                    }
                    else if (kk > 0) {
                        kleft[nr][nc] = kk - 1;
                        q.push({{nr, nc}, {curans + 1, kk - 1}});
                    }
                }
            }
        }
        return ans[rows-1][cols-1];
    }
};
