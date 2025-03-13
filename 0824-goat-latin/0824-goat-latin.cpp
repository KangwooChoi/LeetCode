class Solution {
public:
    string toGoatLatin(string sentence) {
        istringstream in(sentence);
        string word;
        string postfix = "maa";
        char delimiter = ' ';
        string ans = "";
        while (getline(in, word, delimiter)) {
            string add = "";
            char c = word[0];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                add = word + postfix;
            } else {
                add = word.substr(1) + word[0] + postfix; 
            }
            ans += add + ' ';
            postfix += 'a';
        }
        return ans.substr(0, ans.length()-1);
    }
};
//class Solution {
//public:
//    string toGoatLatin(string sentence) {
//        string postfix = "maa";
//        string ans = "";
//        vector<string> words;
//        int left = 0;
//        int right = 0;
//        while (right < sentence.length()) {
//            if (sentence[right++] == ' ') {
//                words.push_back(sentence.substr(left, right-left-1));
//                left = right;
//            }
//        }
//        words.push_back(sentence.substr(left));
//
//        for (auto s : words) {
//            if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' ||
//                s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U') {
//                ans += s + postfix + " ";
//            } else {
//                ans += s.substr(1) + s[0] + postfix + " ";
//            }
//            postfix += 'a';
//        }
//        return ans.substr(0,ans.length()-1); 
//    }
//};