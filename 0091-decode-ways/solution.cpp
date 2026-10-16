class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if (s[i-1] == '0' && s[i-2] == '0') return 0;
            if (s[i-1] != '0') 
                dp[i] = dp[i-1];
            if (s[i-2] != '0') {
                int num = stoi(s.substr(i-2, 2));
                if (num >= 1 && num <= 26) {
                    dp[i] += dp[i-2];
                }
                else if (s[i-1] == '0')
                    return 0;
            }
        }
        return dp[n];
    }
};
