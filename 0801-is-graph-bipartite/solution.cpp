class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colours(n, -1);
        for(int i = 0; i < n; i++) {
            if (colours[i] != -1) continue;
            queue<int> q;
            q.push(i);
            colours[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : graph[u]) {
                    if (colours[v] == colours[u])
                        return false;
                    else if (colours[v] != -1) continue;
                    colours[v] = 1 - colours[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};
