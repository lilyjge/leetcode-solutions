class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end()), ans;
        while (lo < hi) {
            ans = (lo + hi) / 2;
            int needs = 0;
            for(int p : piles) {
                if (p % ans == 0) needs += p / ans;
                else needs += p / ans + 1;
            }
            if (needs <= h) hi = ans;
            else lo = ans + 1;
        }
        return hi;
    }
};
