class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        // Initialize the base cases
        // When str2 is empty, the supersequence is str1 itself
        // (length = row index)
        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        // When str1 is empty, the supersequence is str2 itself
        // (length = col index)
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    // If characters match,
                    // inherit the length from the diagonal + 1
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    // If characters do not match,
                    // take the minimum length option + 1
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                // If characters match, take it from diagonal
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                // If str1’s character is part of the supersequence, move up
                supersequence += str1[row - 1];
                row--;
            } else {
                // If str2’s character is part of the supersequence, move left
                supersequence += str2[col - 1];
                col--;
            }
        }

        // Append any remaining characters
        // If there are leftover characters in str1
        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        // If there are leftover characters in str2
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        // Reverse the built sequence to get the correct order
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};
//class Solution {
//public:
//    string shortestCommonSupersequence(string str1, string str2) {
//        int str1Length = str1.length();
//        int str2Length = str2.length();
//
//        // Initialize the first row (when str1 is empty, the supersequence is
//        // str2's prefix)
//        vector<string> prevRow(str2Length + 1);
//        for (int col = 0; col <= str2Length; col++) {
//            prevRow[col] = str2.substr(0, col);
//        }
//
//        // Fill the DP table row by row
//        for (int row = 1; row <= str1Length; row++) {
//            // Initialize the first column (when str2 is empty, the
//            // supersequence is str1's prefix)
//            vector<string> currRow(str2Length + 1);
//            currRow[0] = str1.substr(0, row);
//
//            for (int col = 1; col <= str2Length; col++) {
//                // If characters match, extend the supersequence from the
//                // diagonal value
//                if (str1[row - 1] == str2[col - 1]) {
//                    currRow[col] = prevRow[col - 1] + str1[row - 1];
//                } else {
//                    // If characters do not match, choose the shorter
//                    // supersequence From previous row (exclude current str1
//                    // char)
//                    string pickS1 = prevRow[col];
//                    // From previous column (exclude current str2 char)
//                    string pickS2 = currRow[col - 1];
//
//                    currRow[col] = (pickS1.length() < pickS2.length())
//                                       ? pickS1 + str1[row - 1]
//                                       : pickS2 + str2[col - 1];
//                }
//            }
//            // Move to the next row (update previous row reference)
//            prevRow = currRow;
//        }
//
//        // Return the shortest common supersequence from the last cell
//        return prevRow[str2Length];
//    }
//};
//class Solution {
//public:
//    string shortestCommonSupersequence(string str1, string str2) {
//        if (str1.empty() && str2.empty()) {
//            return "";
//        }
//        if (str1.empty()) {
//            return str2;
//        }
//        if (str2.empty()) {
//            return str1;
//        }
//        if (str1[0] == str2[0]) {
//            return str1[0] + shortestCommonSupersequence(str1.substr(1), str2.substr(1));
//        } else {
//            string pickStr1 = str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
//            string pickStr2 = str2[0] + shortestCommonSupersequence(str1, str2.substr(1));
//            return (pickStr1.length() < pickStr2.length()) ? pickStr1 : pickStr2;
//        }
//    }
//};
//class Solution {
//public:
//    string shortestCommonSupersequence(string str1, string str2) {
//        int p1 = 0, p2 = 0;
//        return backtrack(str1, str2, p1, p2, "");
//    }
//private:
//    string backtrack(string s1, string s2, int p1, int p2, string res) {
//        if (s1.length() == p1 && s2.length() == p2) {
//            return res;
//        }
//        if (s1[p1] == s2[p2]) {
//            return backtrack(s1, s2, p1+1, p2+1, res+s1[p1]);
//        }
//        string left = "", right = "";
//        if (s1.length() < p1) {
//            left = backtrack(s1, s2, p1+1, p2, res+s1[p1]); 
//        }
//        if (s2.length() < p2) {
//            right = backtrack(s1, s2, p1, p2+1, res+s2[p2]); 
//        }
//        if (left.length() == 0) return right;
//        if (right.length() == 0) return left;
//        return (left.length() <= right.length()) ? left : right;
//    }
//};