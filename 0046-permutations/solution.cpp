class Solution {
public:
    vector<vector<int>> ans;
    vector<int> n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums;
        vector<bool> unused(nums.size(), true);
        vector<int> cur;
        recurse(0, cur, unused);
        return ans;
    }

    void recurse(int i, vector<int>& cur, vector<bool>& unused) {
        if (i == n.size()) {
            ans.push_back(cur);
            return;
        }
        for(int j = 0; j < n.size(); j++) {
            if (unused[j]) {
                cur.push_back(n[j]);
                unused[j] = false;
                recurse(i + 1, cur, unused);
                cur.pop_back();
                unused[j] = true;
            }
        }
    }
};
