class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> umap;
        vector<bool> used(26,false);
        for (int i = 0; i < s.length(); i++) {
            if (umap.find(s[i]) == umap.end()) {
                if (used[t[i]-'a']) return false;
                umap[s[i]] = t[i];
                used[t[i]-'a'] = true;
            } else {
                if (t[i] != umap[s[i]]) return false;
            }
        }
        return true;
    }
};