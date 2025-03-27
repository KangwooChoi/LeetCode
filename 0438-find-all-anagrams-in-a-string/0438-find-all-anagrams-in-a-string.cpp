class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};
        vector<int> p_cnt(26,0);
        vector<int> s_cnt(26,0);
        for (char c : p) {
            p_cnt[c-'a']++;
        }
        int size = p.length();
        for (int i = 0; i < size; i++) {
            s_cnt[s[i]-'a']++;
        }
        vector<int> ans;
        if (compare(s_cnt, p_cnt)) ans.push_back(0);
        for (int i = size; i < s.length(); i++) {
            s_cnt[s[i-size]-'a']--; 
            s_cnt[s[i]-'a']++; 
            if (compare(s_cnt, p_cnt)) ans.push_back(i-size+1);
        }
        return ans;
    }
private:
    bool compare(const vector<int>& s, const vector<int>& p) {
        for (int i = 0; i < 26; i++) {
            if (s[i] != p[i]) return false;
        }
        return true;
    }
};
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        int l = p.length(), n = s.length();    
//        if (l > n) return {};
//        sort(p.begin(), p.end());
//        vector<int> ans;
//        for (int i = 0; i < s.length() - l + 1; i++) {
//            string inter = s.substr(i,l);
//            sort(inter.begin(), inter.end());
//            if (inter == p) ans.push_back(i);
//        }
//        return ans;
//    }
//};