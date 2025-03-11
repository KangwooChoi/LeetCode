class RandomizedSet {
public:
    unordered_map<int,int> valToPos;
    vector<int> nums;

    RandomizedSet() : valToPos(), nums() {
        
    }
    
    bool insert(int val) {
        if (valToPos.find(val) != valToPos.end()) return false;
        valToPos[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (valToPos.find(val) == valToPos.end()) return false;
        int idToRemove = valToPos[val];
        nums[idToRemove] = nums.back();
        valToPos[nums.back()] = idToRemove;
        nums.pop_back();
        return true; 
    }
    
    int getRandom() {
        int idx = rand() % nums.size(); 
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */