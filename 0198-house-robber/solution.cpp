class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            int p1 = 0, p2 = 0;
            if(i-2 >= 0) p1 = dp[i-2];
            if(i-3 >= 0) p2 = dp[i-3];
            dp[i] = max(p1, p2) + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
