class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        recurse(n, n, "");
        return ans;
    }

    void recurse(int open, int close, string cur) {
        if (open > close) return;
        if (open == 0 && close == 0) ans.push_back(cur);
        if (open > 0) recurse(open - 1, close, cur + '(');
        if (close > 0) recurse(open, close - 1, cur + ')');
    }
};
