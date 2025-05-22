class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (const int& n : nums) {
            mp[n]++;
            q.push(n);
        }
    }
    
    int showFirstUnique() {
        while (!q.empty() && mp[q.front()] > 1)
            q.pop();
        return q.size() ? q.front() : -1;
    }
    
    void add(int value) {
        mp[value]++;
        q.push(value);
    }
private:
    map<int, int> mp;
    queue<int> q;
};