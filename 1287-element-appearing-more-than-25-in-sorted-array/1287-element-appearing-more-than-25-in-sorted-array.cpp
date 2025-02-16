class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> umap;
        int maxCnt = 0;
        int ans = -1; 
        for (int i = 0; i < arr.size(); i++) {
            umap[arr[i]]++;
        }
        for (auto [key, val] : umap) {
            if (val > maxCnt) {
                maxCnt = val;
                ans = key;
            }
        }
        return ans;
    }
};