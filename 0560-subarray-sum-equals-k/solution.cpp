class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix;
        prefix.push_back(0);
        for(int i = 0; i < n; i++) {
            prefix.push_back(nums[i] + prefix[i]);
            // cout << i << " " << prefix[i] << endl;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++)
                if (prefix[j] - prefix[i] == k)
                    ans++;
        }
        return ans;
    }
};
