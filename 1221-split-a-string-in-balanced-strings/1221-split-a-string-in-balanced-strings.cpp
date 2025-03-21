class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int ans = 0;
        for (auto c : s) {
            if (c == 'L') balance--;
            if (c == 'R') balance++;
            if (balance == 0) ans++; 
        } 
        return ans;
    }
};