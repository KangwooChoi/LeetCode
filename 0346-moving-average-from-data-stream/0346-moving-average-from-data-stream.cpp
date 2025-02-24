class MovingAverage {
public:
    deque<int> dq;
    int total, limit, n;
    
    MovingAverage(int size) {
        limit = size; 
        total = 0;
        n = 0;
    }
    
    double next(int val) {
        n = min(n+1, limit); 
        total += val;
        dq.push_back(val);
        if (dq.size() > limit) {
            total -= dq.front();
            dq.pop_front();
        }
        return (double)total / n;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */