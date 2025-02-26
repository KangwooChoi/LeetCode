class Solution {
public:
    int romanToInt(string s) {
        map<char,int> values{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            char currChar = s[i];
            int currVal = values[currChar];
            int nextVal = 0;
            if (i+1 < s.length()) {
                char nextChar = s[i+1];
                nextVal = values[nextChar];
            }
            if (currVal < nextVal) {
                ans += nextVal - currVal;
                i += 2;
            } else {
                ans += currVal;
                i += 1;
            }
        } 
        return ans;
    }
};