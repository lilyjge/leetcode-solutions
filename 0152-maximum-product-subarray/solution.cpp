class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mi = nums[0], ans = nums[0];
        for(int i = 1; i < n; i++) {
            int omx = mx;
            mx = max(nums[i], max(nums[i] * mx, nums[i] * mi));
            mi = min(nums[i], min(nums[i] * omx, nums[i] * mi));
            ans = max(ans, mx);
            // cout << i << ' ' << mx << ' ' << mi << endl;
        }
        return ans;
    }
};
