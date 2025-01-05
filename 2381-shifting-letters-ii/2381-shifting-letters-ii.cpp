class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(
            n, 0);  // Initialize a difference array with all elements set to 0.

        for (auto shift : shifts) {
            if (shift[2] == 1) {        // If direction is forward (1):
                diffArray[shift[0]]++;  // Increment at the start index to
                                        // indicate a forward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]--;  // Decrement at the end+1 index to stop the
                                     // effect of the shift.
                }
            } else {                    // If direction is backward (0):
                diffArray[shift[0]]--;  // Decrement at the start index to
                                        // indicate a backward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]++;  // Increment at the end+1 index to stop the
                                     // effect of the shift.
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            if (numberOfShifts < 0)
                numberOfShifts +=
                    26;  // Ensure `numberOfShifts` is non-negative.

            // Calculate the new character by shifting `s[i]`
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};
//class Solution {
//public:
//    string shiftingLetters(string s, vector<vector<int>>& shifts) {
//        string ans = "";
//        for (int i = 0; i < s.length(); i++) {
//            int mv = 0;
//            for (int j = 0; j < shifts.size(); j++) {
//                int start = shifts[j][0], end = shifts[j][1], dir = shifts[j][2];
//                if (start <= i && i <= end) {
//                    if (dir == 0) {
//                        mv--; 
//                    } else {
//                        mv++;
//                    }
//                }
//
//            }
//            int ch = s[i] - 'a' + mv%26;
//            ans += 'a' + (ch+26)%26;
//        }
//        return ans;
//    }
//};
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