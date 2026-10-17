class Solution {
public:
    vector<vector<int>> palindrome;
    vector<vector<string>> ans;
    int n; string s;
    vector<vector<string>> partition(string str) {
        s = str;
        n = s.length();
        palindrome.assign(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++)
                dp(i, j);
        }
        vector<string> e;
        recurse(0, e);
        return ans;
    }

    int dp(int i, int j) {
        if (j < i) return -1;
        if (palindrome[i][j] != 0) return palindrome[i][j];
        if (i == j || (s[i] == s[j] && (j == i + 1 || dp(i+1, j-1) == 1)))
            palindrome[i][j] = 1;
        else
            palindrome[i][j] = -1;
        // cout << i << ' ' << j << ' ' << palindrome[i][j] << endl;
        return palindrome[i][j];
    }

    void recurse(int i, vector<string>& cur) {
        if (i == n) {
            ans.push_back(cur);
            return;
        }
        string nxt = "";
        for(int j = i; j < n; j++) {
            nxt += s[j];
            if (palindrome[i][j] == 1) {
                cur.push_back(nxt);
                recurse(j + 1, cur);
                cur.pop_back();
            }
        }
    }
};
