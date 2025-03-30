class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lasts;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            lasts[c] = i;
        } 
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lasts[s[i]]);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};