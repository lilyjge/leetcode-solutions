class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> mp;
        for(int c : candidates)
            mp[c]++;
        recurse({}, mp, target);
        return ans;
    }

    void recurse(vector<int> cur, unordered_map<int, int> mp, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        } else if (target < 0) return;
        int t = target;
        vector<int> c = cur;
        for(auto [num, cnt] : mp) {
            if (cnt == 0) continue;
            mp[num] = 0;
            while(cnt > 0 && target >= 0) {
                target -= num; cnt--;
                cur.push_back(num);
                recurse(cur, mp, target);
            }
            target = t;
            cur = c;
        }
    }
};
