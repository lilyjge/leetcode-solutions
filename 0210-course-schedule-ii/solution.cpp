class Solution {
public:
    vector<int> adj[2001];
    int ind[2001];

    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        for(vector<int> edge : prereq) {
            ind[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if (ind[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if (ind[cur] == -1) continue;
            ind[cur] = -1;
            ans.push_back(cur);
            for(int v : adj[cur]) {
                if (ind[v] > 0) ind[v]--;
                if (ind[v] == 0) q.push(v);
            }
        }
        if (ans.size() != numCourses) return {};
        return ans;
    }
};
