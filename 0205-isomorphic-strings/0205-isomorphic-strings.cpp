class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> umap;
        unordered_map<char,char> reverse;
        for (int i = 0; i < s.length(); i++) {
            if (umap.find(s[i]) == umap.end()) {
                if (reverse.find(t[i]) != reverse.end()) return false;
                umap[s[i]] = t[i];
                reverse[t[i]] = s[i];
            } else {
                if (t[i] != umap[s[i]]) return false;
            }
        }
        return true;
    }
};