class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char,bool> exists;
        int s_len = source.length();
        int t_len = target.length();
        for (int i = 0; i < s_len; i++) {
            char c = source[i];
            exists[c] = true;
        } 
        for (int i = 0; i < t_len; i++) {
            char c = target[i];
            if (!exists[c]) return -1;
        }
        int p1 = 0, p2 = 0;
        while (p2 < t_len) {
            if (source[p1++%s_len] == target[p2]) p2++;
        }
        return p1 / s_len + (p1%s_len != 0 ? 1 : 0); 
    }
};