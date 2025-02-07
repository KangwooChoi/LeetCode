class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int> umap;
        vector<string> ans;
        for (int i = 0; i < n - 10; i++) {
            string sub = s.substr(i,10);
            if (++umap[sub] == 2) ans.push_back(sub);
        }
        return ans; 
    }
};