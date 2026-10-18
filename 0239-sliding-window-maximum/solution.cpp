class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i < k; i++)
            mp[nums[i]]++;
        vector<int> ans;
        for(int i = k; i <= nums.size(); i++) {
            auto mx = mp.rbegin();
            ans.push_back(mx->first);
            int out = nums[i - k];
            if (mp[out] == 1) {
                mp.erase(out);
            } else {
                mp[out]--;
            }
            if (i != nums.size())
                mp[nums[i]]++;
        }
        return ans;
    }
};
