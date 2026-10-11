#include <random>
using namespace std;

class Solution {
public:
    random_device rd;
    mt19937 gen{rd()};
    discrete_distribution<> dist;

    Solution(vector<int>& w) {
        dist = discrete_distribution<>(w.begin(), w.end());
    }

    int pickIndex() {
        return dist(gen);
    }
};
