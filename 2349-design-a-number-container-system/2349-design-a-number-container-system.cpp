class NumberContainers {
public:
    unordered_map<int,int> index2val;
    unordered_map<int,set<int>> val2indexes;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (index2val.find(index) != index2val.end()) {
            int prev = index2val[index];
            val2indexes[prev].erase(index);
            if (val2indexes[prev].empty()) {
                val2indexes.erase(prev);
            }
        }
        index2val[index] = number;
        val2indexes[number].insert(index);
    }
    
    int find(int number) {
        if (val2indexes.find(number) != val2indexes.end()) {
            return *val2indexes[number].begin();
        } else {
            return -1;
        }
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */