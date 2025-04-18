class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; 
        string res = countAndSay(n-1);
        return helper(res);
    }
private:
    string helper(string res) {
        int len = res.length();
        int cnt = 1;
        string ans = "";
        for (int i = 1; i < len; i++) {
            if (res[i] == res[i-1]) {
                cnt++; 
            } else {
                ans += to_string(cnt);
                ans += res[i-1];
                cnt = 1; 
            }
        }
        ans += to_string(cnt);
        ans += res[len-1];
        return ans;
    }
};