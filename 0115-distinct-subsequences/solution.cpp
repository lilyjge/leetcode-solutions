class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length()) return 0;
        // abab, ab
        // ac, c
        int n = s.length(), m = t.length();
        vector<long long> dp(n);
        for(int i = 0; i < n; i++)
            if (s[i] == t[0])
                dp[i]++;
        for(int i = 0; i < m - 1; i++) {
            char cur = t[i], nxt = t[i + 1];
            int cnt = 0;
            vector<long long> ddp = dp;
            // cout << i << ' ' << cur << ' ' << nxt << endl;
            for(int j = 0; j < n; j++) {
                if (s[j] == nxt) 
                    ddp[j] = cnt;
                if (s[j] == cur) cnt += dp[j];
                // cout << s[j] << ' ' << ddp[j] << ' ' << cnt << endl;
            }
            dp = ddp;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            if (s[i] == t[m-1])
                ans += dp[i];
        return ans;
    }
};
