class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mi = 100005; 
        for(int i = 0; i < prices.size(); i++) {
            if (prices[i] >= mi) continue;
            mi = prices[i];
            for(int j = i + 1; j < prices.size(); j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
