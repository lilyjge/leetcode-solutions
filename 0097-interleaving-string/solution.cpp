class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] = whether can make s3[0...i + j] from s1[0...i] and s2[0...j]
        // dp[0][0] = true
        // if s2[j] == s3[i+j] dp[i][j] = dp[i][j-1]
        // if s1[i] == s3[i+j] dp[i][j] = dp[i-1][j]
        int n = s1.length(), m = s2.length();
        if (s3.length() != n + m) return false;
        if (n < m) {
            swap(n, m);
            swap(s1, s2);
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        int i = 1;
        while(i <= m && s2[i-1] == s3[i-1]) {
            dp[0][i] = 1; i++;
        }
        for(int i = 1; i <= n; i++) {
            if (s1[i-1] == s3[i-1]) {
                dp[i][0] = dp[i-1][0];
            }
            for(int j = 1; j <= m; j++) {
                cout << i << ' ' << j << ' ' << s1[i-1] << ' ' << s2[j-1] <<' ' << s3[i + j - 1] << ' ' << dp[i][j-1] << ' ' << dp[i-1][j] << endl;
                if (s2[j-1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                if (s1[i-1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                cout << dp[i][j] << endl;
            }
        }
        return dp[n][m];
    }
};
