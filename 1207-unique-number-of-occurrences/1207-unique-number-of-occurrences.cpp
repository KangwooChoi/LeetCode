class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> umap;
        vector<int> freq(1001,0);
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            if (umap.find(num) == umap.end()) {
                umap[num] = 1;
            } else umap[num]++;
        }
        for (auto iter = umap.begin(); iter != umap.end(); iter++) {
            freq[iter->second]++;
            if (freq[iter->second] >= 2) return false;
        }
        return true;
    }
};