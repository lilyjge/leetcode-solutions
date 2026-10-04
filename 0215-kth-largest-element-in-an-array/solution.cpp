class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater{});
        return v[k-1];
    }
};
