class Solution {
public:
    unordered_map<int, int> dp[21]; // dp[i][j] = num ways to make j with nums[i...n]
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp[n-1][nums[n-1]]++;
        dp[n-1][-nums[n-1]]++;
        return recurse(0, nums, target);
    }

    int recurse(int i, vector<int>& nums, int target) {
        // cout << i << ' ' << target << endl;
        if (i >= nums.size()) return 0;
        if (dp[i].contains(target)) {
            return dp[i][target];
        } 
        dp[i][target] += recurse(i + 1, nums, target + nums[i]);
        dp[i][target] += recurse(i + 1, nums, target - nums[i]);
        return dp[i][target];
    }
};
