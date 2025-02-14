class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary(words.begin(), words.end());
        vector<string> ans;
        for (const string& word : words) {
            const int length = word.length();
            vector<bool> dp(length+1,false);
            dp[0] = true;
            for (int i = 1; i <= length; i++) {
                for (int j = (i == length ? 1 : 0); !dp[i] && j < i; j++) {
                    dp[i] = dp[j] && dictionary.count(word.substr(j, i-j));
                }
            }
            if (dp[length]) ans.push_back(word);
        }
        return ans; 
    }
};