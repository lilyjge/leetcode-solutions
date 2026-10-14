class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";
        unordered_map<char, int> needed;
        for(char c : t) needed[c]++;
        int tot = n;
        int i = 0, j = 0;
        pair<int, int> ans;
        while(tot > 0 && j < m) {
            if (needed.find(s[j]) != needed.end()) {
                if (needed[s[j]] > 0) tot--; 
                needed[s[j]]--;
            }
            j++;
        }
        ans = {0, j};
        if (tot > 0) return "";
        while (i < m) {
            // cout << cur << endl;
            if (needed.find(s[i]) != needed.end()) {
                needed[s[i]]++;
                if (needed[s[i]] > 0) tot++;
            }
            i++; 
            while(tot > 0 && j < m) {
                if (needed.find(s[j]) != needed.end()) {
                    if (needed[s[j]] > 0) tot--; 
                    needed[s[j]]--;
                    // cout << "need " << needed[s[j]] << ' ';
                    // cout << tot << ' ';
                }
                // cout << j << ' ' << s[j] << endl;
                j++;
            }
            if (tot > 0) return s.substr(ans.first, ans.second - ans.first);
            if (j - i < ans.second - ans.first)
                ans = {i, j};
        }
        return s.substr(ans.first, ans.second - ans.first);
    }
};
