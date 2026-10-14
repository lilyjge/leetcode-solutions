class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j] lcs for text1[0..i], text2[0...j]
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + int(text1[i-1] == text2[j-1]));
                // cout << dp[i][j] << ' ';
            } cout << endl;
        }
        return dp[n][m];
    }
};
