class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to everything it unlocks, decrement on vis
        // if req == 0 put into queue
        vector<vector<int>> unlocks(numCourses, vector<int>());
        vector<int> needs(numCourses, 0);
        for(vector<int> req : prerequisites) {
            unlocks[req[0]].push_back(req[1]);
            needs[req[1]]++;
        } 
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(needs[i] == 0) {
                q.push(i);
                needs[i]--;
            }
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i : unlocks[cur]) {
                needs[i]--;
                if(needs[i] == 0) {
                    q.push(i);
                    needs[i]--;
                }
            }
        }
        for(int i = 0; i < numCourses; i++)
            if (needs[i] > 0 ) return false;
        return true;
    }
};
