class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while (str.length() <= k) {
            string add = "";
            for (char c : str) {
                add.push_back(c+1);
            }
            str += add;
        } 
        return str[k-1];
    }
};