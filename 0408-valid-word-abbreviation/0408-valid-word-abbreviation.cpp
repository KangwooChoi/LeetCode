class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int jump = 0, index = 0;
        for (int i = 0; i < abbr.size(); i++) {
            if ((isdigit(abbr[i]))) {
                if (jump == 0 && (abbr[i] == '0')) return false;
                jump = jump*10 + (abbr[i] - '0');
            } else {
                index += jump;
                jump = 0;
                if (abbr[i] != word[index]) return false;
                index++;
            }
        }
        index += jump;
        return index == word.size();
    }
};
//class Solution {
//public:
//    bool validWordAbbreviation(string word, string abbr) {
//        if (abbr.length() > word.length()) return false;
//        int p = 0, abbr_size = 0;
//        for (int i = 0; i < word.size() || i < abbr.size(); ) {
//            string jump = "";
//            while (isdigit(abbr[p])) {
//                jump += abbr[p++];
//            }
//            if (jump != "") {
//                if (jump[0] == '0') return false;
//                i += stoi(jump);
//                abbr_size += stoi(jump);
//                continue;
//            }
//            if (abbr[p++] != word[i++]) return false; 
//            abbr_size++;
//        }
//        return abbr_size == word.length() && p == abbr.length(); 
//    } 
//};
//class Solution {
//public:
//    bool validWordAbbreviation(string word, string abbr) {
//        if (word.size() < abbr.size()) return false;
//        int n = word.size();
//        int abbr_size = 0;
//        for (int i = 0; i < abbr.size();) {
//            if (abbr[i] == '0') return false;
//            if (isdigit(abbr[i])) {
//                int start_idx = i;
//                while (i < abbr.size() && isdigit(abbr[i])) {
//                    i++;
//                }
//                abbr_size += stoi(abbr.substr(start_idx, i - start_idx));
//            } else {
//                if (abbr_size >= n || word[abbr_size] != abbr[i]) return false;
//                abbr_size++;
//                i++;
//            }
//        }
//        return abbr_size == n;
//    }
//};