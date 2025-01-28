class Solution {
public:
    int romanToInt(string s) {
        int p = 0;
        int ans = 0;
        s += ' ';
        while (p < s.length()) {
            if (s[p] == 'M') ans += 1000;
            else if (s[p] == 'D') ans += 500;
            else if (s[p] == 'C') {
                if (s[p+1] == 'M') {
                    ans += 900;
                    p++;
                } else if (s[p+1] == 'D') {
                    ans += 400;
                    p++;
                } else {
                    ans += 100;
                }
            }
            else if (s[p] == 'L') ans += 50;
            else if (s[p] == 'X') {
                if (s[p+1] == 'C') {
                    ans += 90;
                    p++;
                } else if (s[p+1] == 'L') {
                    ans += 40;
                    p++;
                } else {
                    ans += 10;
                } 
            } else if (s[p] == 'V') ans += 5;
            else if (s[p] == 'I') {
                if (s[p+1] == 'X') {
                    ans += 9; 
                    p++;
                } else if (s[p+1] == 'V') {
                    ans += 4;
                    p++;
                } else {
                    ans += 1;
                }
            } 
            p++;
        } 
        return ans;
    }
};