class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            umap[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto content : umap) {
            ans.push_back(content.second);
        } 
        return ans;
    }
};