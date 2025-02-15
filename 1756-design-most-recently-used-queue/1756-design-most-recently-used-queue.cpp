class MRUQueue {
public:
    deque<int> dq;

    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
        } 
    }
    
    int fetch(int k) {
        auto iter = dq.begin(); 
        while (--k > 0) {
            iter++;
        }
        int temp = *iter;
        dq.erase(iter);
        dq.push_back(temp);
        return temp;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */