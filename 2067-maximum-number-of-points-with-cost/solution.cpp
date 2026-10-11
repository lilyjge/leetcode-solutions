typedef long long ll;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<ll> best(cols);
        for(int r = 0; r < rows; r++) {
            vector<ll> left(cols), right(cols); // best value coming from that side for ind
            left[0] = best[0]; right[cols-1] = best[cols-1];
            for(int c = 1; c < cols; c++) 
                left[c] = max(best[c], left[c-1] - 1);
            for(int c = cols - 2; c >= 0; c--)
                right[c] = max(best[c], right[c+1]-1);
            for(int c = 0; c < cols; c++)
                best[c] = points[r][c] + max(left[c], right[c]);
        }
        ll ans = 0;
        for(int c = 0; c < cols; c++)
            ans = max(ans, best[c]);
        return ans;
    }
};
