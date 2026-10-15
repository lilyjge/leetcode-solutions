class MedianFinder {
public:
    map<int, int> mp;
    int tot = 0;
    MedianFinder() {
    }
    
    void addNum(int num) {
        mp[num]++;
        tot++;
    }
    
    double findMedian() {
        int med = (tot / 2) + 1;
        if (tot % 2 == 0) med--;
        int cnt = 0, prev = 0;
        for(auto e : mp) {
            if (cnt == -1) {
                return (prev + e.first) / 2.0;
            }
            cnt += e.second;
            if (cnt >= med) {
                if (cnt == med && tot % 2 == 0) {
                    cnt = -1; prev = e.first;
                }
                else return e.first;
            }
        }
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
