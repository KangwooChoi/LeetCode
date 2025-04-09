class MovingAverage {
public:
    int limit;
    queue<int> que;
    double currSum;

    MovingAverage(int size) {
        limit = size;     
        currSum = 0;
    }
    
    double next(int val) {
        currSum += val;
        que.push(val);     
        while (que.size() > limit) {
            currSum -= que.front();
            que.pop();
        }
        return currSum / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */