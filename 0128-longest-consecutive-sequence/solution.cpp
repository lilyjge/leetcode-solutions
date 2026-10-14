class Solution {
public:
    unordered_map<int, int> p;
    unordered_map<int, int> rank;
    int find_set(int d) {
        if (d != p[d])
            p[d] = find_set(p[d]);
        return p[d];
    }

    int longestConsecutive(vector<int>& nums) {
        for(int n : nums) {
            p[n] = n; rank[n] = 1;
        }
        for(int n : nums) {
            int pn = find_set(n);
            // cout << n << ' ' << p[n] << ' ' << rank[pn] << endl;
            if (p.find(n-1) != p.end()) {
                int pu = find_set(n-1);
                p[pu] = pn;
                if (pu != pn) {
                    rank[pn] += rank[pu];
                    rank[pu] = 0; 
                }
                // cout << "n-1 " << n-1 << ' ' << p[pu] << ' ' << rank[pu] << endl;
            }
            if (p.find(n+1) != p.end()) {
                int pu = find_set(n+1);
                p[pu] = pn;
                if (pu != pn) {
                    rank[pn] += rank[pu];
                    rank[pu] = 0; 
                }
                // cout << "n+1 " << n+1 << ' ' << p[pu] << ' ' << rank[pu] << endl;
            }
            // cout << n << ' ' << p[n] << ' ' << rank[pn] << endl;
        }
        int ans = 0;
        for(auto e : rank)
            ans = max(ans, e.second);
        return ans;
    }
};
