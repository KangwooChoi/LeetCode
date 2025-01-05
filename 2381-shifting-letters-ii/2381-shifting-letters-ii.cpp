class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            int mv = 0;
            for (int j = 0; j < shifts.size(); j++) {
                int start = shifts[j][0], end = shifts[j][1], dir = shifts[j][2];
                if (start <= i && i <= end) {
                    if (dir == 0) {
                        mv--; 
                    } else {
                        mv++;
                    }
                }

            }
            int ch = s[i] - 'a' + mv%26;
            ans += 'a' + (ch+26)%26;
        }
        return ans;
    }
};
//class Solution {
//public:
//    string shiftingLetters(string s, vector<vector<int>>& shifts) {
//        string ans = "";
//        vector<int> mv(s.length(), 0);
//        for (auto shift: shifts) {
//            int dir = shift[2], start = shift[0], end = shift[1];
//            if (dir == 0) {
//                for (int i = start; i <= end; i++) {
//                    mv[i]--;
//                }
//            } else {
//                for (int i = start; i <= end; i++) {
//                    mv[i]++;
//                }
//            }
//        }
//        for (int j = 0; j < s.length(); j++) {
//            mv[j] %= 26;
//            int plus = (s[j] -'a' + mv[j]) % 26;
//            char c = 'a' + (plus+26)%26;
//            ans += c;
//        }
//
//        return ans;
//    }
//};