class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char prev = word[0];
        int pre_cnt = 1;
        for (int i = 1;i < word.length(); i++) {
            if (prev == word[i]) {
                pre_cnt++;
            } else {
                prev = word[i];
                ans += pre_cnt - 1;
                pre_cnt = 1;
            }
        }
        ans += pre_cnt - 1;
        return ans;
    }
};
//class Solution {
//public:
//    int possibleStringCount(string word) {
//        unordered_map<char,int> freq;
//        for (char c : word) {
//            freq[c]++;
//        } 
//        int ans = 1;
//        for (auto [c, f] : freq) {
//            ans += f - 1;
//        }
//        return ans;
//    }
//};