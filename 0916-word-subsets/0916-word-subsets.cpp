class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> w2_freq(26,0);
        for (auto word : words2) {
            vector<int> freq(26,0);
            for (char c : word) {
                freq[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                w2_freq[i] = max(w2_freq[i], freq[i]);
            }
        } 
        vector<string> ans;
        for (auto word : words1) {
            vector<int> freq(26,0);
            for (char c : word) {
                freq[c-'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (w2_freq[i] > freq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(word);
        }
        return ans;
    }
};