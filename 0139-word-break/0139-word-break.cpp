class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (string word : wordDict) {
                if (i < word.length()-1) continue;

                if (i == word.length()-1 || dp[i-word.length()]) {
                    if (s.substr(i-word.length()+1, word.length()) == word) {
                        dp[i] = true;
                        break;
                    }
                }

            }
        }
        return dp[s.length()-1];
    }
};
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> words(wordDict.begin(), wordDict.end());
//        queue<int> queue;
//        vector<bool> seen(s.length(), false);
//        queue.push(0);
//
//        while (!queue.empty()) {
//            int start = queue.front();
//            queue.pop();
//
//            if (start == s.length()) {
//                return true;
//            }
//
//            for (int end = start + 1; end <= s.length(); end++) {
//                if (seen[end]) {
//                    continue;
//                }
//
//                if (words.find(s.substr(start, end - start)) != words.end()) {
//                    queue.push(end);
//                    seen[end] = true;
//                }
//            }
//        }
//
//        return false;
//    }
//};
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        int n = wordDict.size();
//        reverse(wordDict.begin(), wordDict.end());
//        for (int i = 0; i < n; i++) {
//            int length = wordDict[i].length();
//            if (s.substr(0, length) == wordDict[i]) {
//                bool ret = backtrack(s.substr(length), wordDict);
//                if (ret) return true;
//            }
//        }
//        return false; 
//    }
//private:
//    bool backtrack(string s, vector<string>& wordDict) {
//        if (s == "") return true;
//        for (int i = 0; i < wordDict.size(); i++) {
//            int length = wordDict[i].length();
//            if (s.substr(0, length) == wordDict[i]) {
//                bool ret = backtrack(s.substr(length), wordDict);
//                if (ret) return true;
//            }
//        }
//        return false;
//    }
//};