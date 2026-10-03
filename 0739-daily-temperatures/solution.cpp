class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            int cur = temperatures[i];
            while(!s.empty() && cur > temperatures[s.top()]) {
                int t = s.top(); s.pop();
                ans[t] = i - t;
            }
            s.push(i);
        }
        return ans;
    }
};
