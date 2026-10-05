class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        v = candidates;
        helper(0, target, {});
        return ans;
    }

    void helper(int i, int target, vector<int> cur) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int j = i; j < v.size(); j++) {
            cur.push_back(v[j]);
            helper(j, target - v[j], cur);
            cur.pop_back();
        }
    }
};
