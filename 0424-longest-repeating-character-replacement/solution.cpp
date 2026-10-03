class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnts[26] = {};
        int i = 0, j = 1;
        int ans = 1;
        cnts[s[0] - 'A']++;
        int maxFreq = 1;
        char maxChar = s[0];
        while(j < s.size()) {
            cnts[s[j] - 'A']++;
            if (cnts[s[j] - 'A'] > maxFreq) {
                maxFreq = cnts[s[j] - 'A'];
                maxChar = s[j];
            }
            // cout << s[j] << ' ' << cnts[s[j] - 'A'] << endl;
            // cout << s[i] << " " << s[j] << " " << i << " " << j << endl;
            while(j - i + 1 - maxFreq > k) {
                cnts[s[i] - 'A']--;
                i++;
                maxFreq = cnts[s[i] - 'A'];;
                for(int i = 0; i < 26; i++) {
                    if (cnts[i] > maxFreq) {
                        maxFreq = cnts[i];
                    }
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
