class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        unordered_map<char, int> letters;
        for(char c : p)
            letters[c]++;
        int n = s.size(), m = p.size();
        int tot = m;
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            if (letters.find(s[i]) != letters.end()) {
                if (letters[s[i]] > 0)
                    tot--;
                letters[s[i]]--;
            }
        }
        if (tot == 0)
            ans.push_back(0);
        for(int i = 1; i <= n-m; i++) {
            if (letters.find(s[i-1]) != letters.end()) {
                letters[s[i-1]]++; 
                if (letters[s[i-1]] > 0)
                    tot++;
            }
            if (letters.find(s[i+m-1]) != letters.end()) {
                if (letters[s[i+m-1]] > 0)
                    tot--;
                letters[s[i+m-1]]--; 
            }
            // cout << i << ' ' << s[i-1] << ' ' << s[i+m-1] << ' ' << tot << endl;
            if (tot == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
