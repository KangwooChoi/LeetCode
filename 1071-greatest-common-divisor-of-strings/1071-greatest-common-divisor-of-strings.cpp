class Solution {
public:
    bool checker(string str1, string str2) {
        if (str1.length() % str2.length() != 0) return false;
        int step = str2.length();

        int cnt = str1.length() / str2.length();

        //cout << "1: " << str1 << ", " << str2 << endl;

        for (int i = 0; i < cnt; i++) {
            if (str1.substr(i*step, step).compare(str2)) {
                return false;
            }
        }

        //cout << "2: " << str1 << ", " << str2 << endl;

        return true;

    }

    string gcdOfStrings(string str1, string str2) {
        int init_cnt = str2.length();
        string div = str2;
        while (div.length() > 0) {

            if (checker(str2, div)) {
                if (checker(str1, div))
                    return div;
            }
            div.erase(init_cnt--, 1);
 
        }
        return "";

    }
};