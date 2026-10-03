class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int c : coins)
            if (c <= amount)
                dp[c] = 1;
        for(int i = 0; i <= amount; i++) {
            if(dp[i] != -1) continue;
            for(int c : coins) {
                if(i >= c && dp[i - c] != -1)
                    dp[i] = (dp[i] == -1) ? dp[i-c] + 1 : min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount];
    }
};
