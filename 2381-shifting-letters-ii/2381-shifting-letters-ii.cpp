class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans;
        int n = s.length();
        vector<int> diff(n,0);
        for (auto shift : shifts) {
            if (shift[2] == 1) {
                diff[shift[0]]++;
                if (shift[1] + 1 < n) {
                    diff[shift[1] + 1]--;
                }
            } else {
                diff[shift[0]]--;
                if (shift[1] + 1 < n) {
                    diff[shift[1] + 1]++;
                }
            }
        } 
        int numOfShift = 0;
        for (int i = 0; i < n; i++) {
            numOfShift = (numOfShift + diff[i]) % 26;
            if (numOfShift < 0) {
                numOfShift += 26;
            }
            char temp = 'a' + (s[i] - 'a' + numOfShift) % 26; 
            ans.push_back(temp);
        }
        return ans;
    }
};