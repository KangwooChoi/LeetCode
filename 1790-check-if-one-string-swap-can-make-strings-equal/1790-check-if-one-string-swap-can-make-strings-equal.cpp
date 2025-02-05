class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<char> diff_s1;
        vector<char> diff_s2;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff_s1.push_back(s1[i]);
                diff_s2.push_back(s2[i]);
                if (diff_s1.size() > 2) return false;
            }
        }
        if (diff_s1.size() == 0) return true;
        else if (diff_s1.size() == 2) {
            if (diff_s1[0] == diff_s2[1] && diff_s1[1] == diff_s2[0]) return true;
        }
        return false;
    }
};