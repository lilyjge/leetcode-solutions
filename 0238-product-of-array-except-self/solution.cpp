class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1), post(n + 1);
        pre[0] = 1; post[n] = 1;
        for(int i = 0; i < n; i++) {
            pre[i + 1] = nums[i] * pre[i];
            post[n - i - 1] = nums[n - i - 1] * post[n - i];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = pre[i] * post[i + 1];
        }
        return ans;
    }
};
