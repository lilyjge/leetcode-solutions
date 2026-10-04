class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<bool> canBreak(s.size(), false);
        for(string w : wordDict) {
            dict.insert(w);
        }
        for(int l = 0; l < s.length(); l++) {
            if (l != 0 && !canBreak[l-1]) continue;
            string curWord = "";
            for(int r = l; r < s.length(); r++) {
                curWord += s[r];
                if (dict.contains(curWord))
                    canBreak[r] = true;
            }
        }
        return canBreak[s.size()-1];
    }
};
