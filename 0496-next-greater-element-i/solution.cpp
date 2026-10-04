class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> big(nums2.size(), -1);
        unordered_map<int, int> vals;
        for(int i = 0; i < nums2.size(); i++) {
            vals[nums2[i]] = i;
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                big[s.top()] = i; s.pop();
            }
            s.push(i);
        }
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            if (big[vals[nums1[i]]] != -1)
                ans[i] = nums2[big[vals[nums1[i]]]];
        }
        return ans;
    }
};
