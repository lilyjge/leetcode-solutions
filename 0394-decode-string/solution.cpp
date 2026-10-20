class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string pre = "", post = "", k = "";
        int i = 0;
        while(i < n && isalpha(s[i])) {
            pre += s[i]; i++;
        }
        if (i == n) return s; // base case, whole string letters
        while(i < n && isdigit(s[i])) {
            k += s[i]; i++;
        }
        i++;
        int j = i;
        int st = 1, end = 0;
        while(j < n && st != end) {
            if (s[j] == '[') st++;
            if (s[j] == ']') end++;
            j++;
        }
        string mid = decodeString(s.substr(i, j - i - 1));
        int kk = stoi(k);
        for(int i = 0; i < kk; i++)
            pre += mid;
        pre += decodeString(s.substr(j));
        return pre;
    }
};
