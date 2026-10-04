typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums) 
            freq[i]++;
        vector<pi> ordered;
        for(auto e : freq)
            ordered.push_back({e.second, e.first});
        sort(ordered.begin(), ordered.end(), greater<>());
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(ordered[i].second);
        return ans;
    }
};
