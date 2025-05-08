class Logger {
public:
    unordered_map<string,int> umap;

    Logger() {
        unordered_map<string,int> umap;     
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (umap.find(message) == umap.end()) {
            umap[message] = timestamp + 10;
            return true;
        } else {
            if (umap[message] <= timestamp) {
                umap[message] = timestamp + 10;
                return true;
            }
            else return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */