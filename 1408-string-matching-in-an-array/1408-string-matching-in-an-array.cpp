class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        vector<bool> maps(words.size(), false);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                if (words[i].length() >= words[j].length()) {
                    for (int k = 0; k + words[j].length() <= words[i].length(); k++) {
                        if (words[i].substr(k, words[j].length()) == words[j]) {
                            if (maps[j] == false) {
                                maps[j] = true;
                                ans.push_back(words[j]);
                            }
                        }
                    }
                }
            }
        }
        return ans; 
    }
};