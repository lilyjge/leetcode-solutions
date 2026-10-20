class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp[i] = min(dp[i-1] + costs[0], dp[i-7] + costs[1], dp[i-30] + costs[2]);
        vector<int> dp(366);
        int j = 0;
        
        for(int i = 1; i <= 365; i++) {
            if (i == days[j]) {
                dp[i] = dp[i-1] + costs[0];
                j++;
            }
            else {
                dp[i] = dp[i-1];
            }
            dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);   
            // cout << i << ' ' << dp[i] << endl;
            if (j == days.size()) break;
        }
        return dp[days[days.size()-1]];
    }
};
