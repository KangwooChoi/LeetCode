class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> umap;
        for (int i = 0; i < order.length(); i++) {
            umap[order[i]] = 0;
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (!umap.count(s[i])) {
                ans += s[i];
            } else {
                umap[s[i]]++;
            }
        }
        for (int i = 0; i < order.length(); i++) {
            int count = umap[order[i]];
            while (count-- > 0) {
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};