class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int n = words[i].length(), m = words[j].length();
                if (n > m) continue;
                if (words[i] != words[j].substr(0, n)) continue;
                if (words[i] != words[j].substr(m-n, n)) continue;
                ans++;
            }
        }
        return ans;
    }
};