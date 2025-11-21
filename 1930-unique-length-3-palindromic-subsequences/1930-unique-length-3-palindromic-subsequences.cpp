//class Solution {
//public:
//    int countPalindromicSubsequence(string s) {
//        int ans = 0;
//        vector<int> first(26,-1);
//        vector<int> last(26,-1);
//        for (int i = 0; i < s.length(); i++) {
//            char c = s[i];
//            if (first[c-'a'] == -1) first[c-'a'] = i;
//            else last[c-'a'] = i;
//        }
//        for (int i = 0; i < 26; i++) {
//            if (first[i] == -1) continue;
//            unordered_set<char> between;
//            for (int j = first[i] + 1; j < last[i]; j++) {
//                between.insert(s[j]);
//            }
//            ans += between.size();
//        }
//        return ans;
//    }
//};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;

            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            ans += between.size();
        }
        return ans;
    }
};
//class Solution {
//public:
//    int countPalindromicSubsequence(string s) {
//        int ans = 0;
//        vector<vector<int>> loc(26);
//        for (int i = 0; i < s.length(); i++) {
//            int index = s[i] - 'a';
//            loc[index].push_back(i);
//        }
//        for (auto v: loc) {
//            if (v.size() < 2) continue;
//            int start = v[0];
//            int end = v[v.size()-1];
//            unordered_set<char> between;
//            for (int j = start + 1; j < end; j++) {
//                between.insert(s[j]);
//            }
//            ans += between.size();
//        }
//        return ans;
//    }
//};