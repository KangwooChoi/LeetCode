class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};
//class Solution {
//public:
//    bool valid(string str1, string str2, int k) {
//        int len1 = str1.size(), len2 = str2.size();
//        if (len1 % k > 0 || len2 % k > 0) {
//            return false;
//        } else {
//            string base = str1.substr(0, k);
//            int n1 = len1 / k, n2 = len2 / k;
//            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
//        }
//    }
//    string joinWords(string str, int k) {
//        string ans = "";
//        for (int i = 0; i < k; ++i) {
//            ans += str;
//        }
//        return ans;
//    }
//    
//    
//    string gcdOfStrings(string str1, string str2) {
//        int len1 = str1.length(), len2 = str2.length();
//        for (int i = min(len1, len2); i >= 1; --i) {
//            if (valid(str1, str2, i)) {
//                return str1.substr(0, i);
//            }
//        }
//        return "";
//    }
//};
//class Solution {
//public:
//    bool checker(string str1, string str2) {
//        if (str1.length() % str2.length() != 0) return false;
//        int step = str2.length();
//
//        int cnt = str1.length() / str2.length();
//
//        //cout << "1: " << str1 << ", " << str2 << endl;
//
//        for (int i = 0; i < cnt; i++) {
//            if (str1.substr(i*step, step).compare(str2)) {
//                return false;
//            }
//        }
//
//        //cout << "2: " << str1 << ", " << str2 << endl;
//
//        return true;
//
//    }
//
//    string gcdOfStrings(string str1, string str2) {
//        int init_cnt = str2.length();
//        string div = str2;
//        while (div.length() > 0) {
//
//            if (checker(str2, div)) {
//                if (checker(str1, div))
//                    return div;
//            }
//            div.erase(init_cnt--, 1);
// 
//        }
//        return "";
//
//    }
//};