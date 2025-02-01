class RandomizedSet {
private:
    unordered_map<int,int> valToPos;
    vector<int> nums;

public:
    RandomizedSet() : valToPos{}, nums{} {
        
    }
    
    bool insert(int val) {
        if (valToPos.find(val) != valToPos.end()) {
            return false;
        } else {
            int index = nums.size();
            nums.push_back(val);
            valToPos[val] = index;
            return true;
        }
    }
    
    bool remove(int val) {
        if (valToPos.find(val) == valToPos.end()) {
            return false;
        } else {
            int indexToRemove = valToPos[val];
            nums[indexToRemove] = nums.back();
            valToPos[nums.back()] = indexToRemove;
            nums.pop_back();
            valToPos.erase(val);
            return true;
        }
        
    }
    
    int getRandom() {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */