class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> dis;
        int n = beginWord.length();
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++) {
            dis[wordList[i]] = -1;
            for(int j = i + 1; j < wordList.size(); j++) {
                string s = wordList[i], t = wordList[j];
                int diff = 0;
                for(int k = 0; k < n; k++) {
                    if (s[k] != t[k])
                        diff++;
                }
                if (diff == 1) {
                    adj[s].push_back(t);
                    adj[t].push_back(s);
                }
            }
        }
        queue<string> q;
        q.push(beginWord);
        dis[beginWord] = 1;
        while(!q.empty()) {
            string s = q.front(); q.pop();
            if (s == endWord) return dis[s];
            for(string t : adj[s]) {
                if (dis[t] == -1) {
                    dis[t] = dis[s] + 1;
                    q.push(t);
                }
            }
        }
        return 0;
    }
};
