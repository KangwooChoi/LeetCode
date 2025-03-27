class BrowserHistory {
public:
    vector<string> history;
    int p;

    BrowserHistory(string homepage) {
        history.push_back(homepage); 
        p = 0;
    }
    
    void visit(string url) {
        while (p != history.size() - 1) {
            history.pop_back();
        }
        history.push_back(url); 
        p++;
    }
    
    string back(int steps) {
        p = max(p - steps, 0); 
        return history[p];
    }
    
    string forward(int steps) {
        p = min(p + steps, (int)history.size()-1); 
        return history[p];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */