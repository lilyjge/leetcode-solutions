class Solution {
public:
    int p[10001];

    int find_set(int d) {
        if (d != p[d])
            p[d] = find_set(p[d]);
        return p[d];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 1; i <= n; i++) p[i] = i;
        for (vector<int> e : edges) {
            int u = e[0], v = e[1];
            int du = find_set(u), dv = find_set(v);
            if (du == dv) return e;
            p[du] = dv;
        }
        return edges[n-1];
    }
};
