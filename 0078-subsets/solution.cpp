class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;

    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        n = nums.size();
        vector<int> e;
        recurse(e, 0);
        return ans;
    }

    void recurse(vector<int> cur, int i) {
        if (i == n) ans.push_back(cur);
        else {
            recurse(cur, i + 1);
            cur.push_back(v[i]);
            recurse(cur, i + 1);
        }
    }
};
