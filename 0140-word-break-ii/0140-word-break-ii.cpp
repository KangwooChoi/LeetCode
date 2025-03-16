class Solution {
public:
    vector<string> ans;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        backtrack(s, wordDict, "");
        return ans;
    }
private:
    void backtrack(string s, vector<string>& wordDict, string res) {
        for (int i = 0; i < wordDict.size(); i++) {
            string word = wordDict[i];
            if (word.length() > s.length()) continue;
            if (word == s.substr(0,word.length())) {
                if (word.length() == s.length()) {
                    res += word;
                    ans.push_back(res);
                    return;
                }
                backtrack(s.substr(word.length()), wordDict, res + word + " ");
            }
        }
        return;
    }
};
//class Solution {
//public:
//    vector<string> ans;
//    vector<string> wordBreak(string s, vector<string>& wordDict) {
//        sort(wordDict.begin(), wordDict.end());
//        backtrack(s, wordDict, ""); 
//        return ans;
//    }
//    void backtrack(string s, vector<string>& wordDict, string res) {
//        for (int i = 0; i < wordDict.size(); i++) {
//            string word = wordDict[i];
//            if (word.length() > s.length()) continue;
//            if (word == s.substr(0,word.length())) {
//                if (word.length() == s.length()) {
//                    res += word;
//                    ans.push_back(res);
//                    return;
//                } else {
//                    backtrack(s.substr(word.length()), wordDict, res+word+" ");
//                }
//            }
//        }
//    }
//};