class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        recurse(cur, 0, nums);
        return ans;
    }

    void recurse(vector<int>& cur, int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(cur); return;
        }
        int nxt = i + 1;
        while(nxt < nums.size() && nums[i] == nums[nxt])
            nxt++;
        recurse(cur, nxt, nums);
        for(int j = i; j < nxt; j++) {
            cur.push_back(nums[j]);
            recurse(cur, nxt, nums);
        }
        for(int j = i; j < nxt; j++)
            cur.pop_back();
    }
};
