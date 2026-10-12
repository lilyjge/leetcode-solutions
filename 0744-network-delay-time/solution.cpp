typedef pair<int, int> pi;
// const int INT_MAX = 100000;

class Solution {
public:
    vector<pi> adj[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int> edge : times)
            adj[edge[0]].push_back({edge[1], edge[2]});
        vector<int> dis(n + 1, INT_MAX); 
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, k});
        while(!pq.empty()) {
            auto e = pq.top(); pq.pop();
            int curdis = e.first, u = e.second;
            // cout << "visiting " << u << " curdis " << curdis << endl;
            if (dis[u] != INT_MAX) continue;
            dis[u] = curdis;
            for(pi edge : adj[u]) {
                int v = edge.first, w = edge.second;
                if (dis[v] > dis[u] + w)
                    pq.push({dis[u] + w, v});
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};
