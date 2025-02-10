class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for (char c : s) {
            freq[c-'a']++;
        }
        int maxCnt = 0, letter = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxCnt) {
                maxCnt = freq[i];
                letter = i;
            }
        }
        if (maxCnt > (s.length() + 1) / 2) {
            return "";
        }
        string ans = s;
        int index = 0;
        while (freq[letter] != 0) {
            ans[index] = char(letter+'a');
            index += 2;
            freq[letter]--;
        }
        for(int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                ans[index] = char(i+'a');
                index += 2;
                freq[i]--;
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    string reorganizeString(string s) {
//        vector<int> freq(26,0);
//        int total = s.length();
//        for (char c: s) {
//            freq[c-'a']++;
//        }
//        int mostOccur = 0;
//        int index = -1;
//        for (int i = 0; i < 26; i++) {
//            if (mostOccur < freq[i]) index = i;
//            mostOccur = max(mostOccur, freq[i]);
//        } 
//        if (mostOccur * 2 <= total + 1) {
//            char mostChar = 'a' + index;
//            string ans = "";
//            int cnt = 0;
//            for (char c : s) {
//                if (c == mostChar) continue;
//                if (cnt < mostOccur) {
//                    ans += mostChar;
//                    cnt++;
//                }
//                ans += c;
//            } 
//            return cnt == freq[index] ? ans : ans + mostChar;
//        }
//        return "";
//    }
//};