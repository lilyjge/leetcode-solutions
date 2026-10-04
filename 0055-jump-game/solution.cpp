class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if (cur - i <= nums[i])
                cur = i;
        }
        return cur == 0;
    }
};
