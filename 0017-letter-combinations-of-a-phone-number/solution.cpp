class Solution {
public:
    unordered_map<int, string> phone = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        recurse(0, digits, "");
        return ans;
    }

    void recurse(int i, string& digits, string cur) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }
        int dig = digits[i] - '0';
        for(char c : phone[dig]) {
            recurse(i + 1, digits, cur + c);
        }
    }
};
