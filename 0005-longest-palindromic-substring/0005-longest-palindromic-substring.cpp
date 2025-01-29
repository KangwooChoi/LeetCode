class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int l = n;
        while (l>0) {
            for (int i = 0; i < n-l+1; i++) {
                string temp = s.substr(i,l);
                if(isPalindrome(temp)) return temp;
            }
            l--;
        }
        return "";
    }
private:
    bool isPalindrome(string p) {
        int left = 0, right = p.length()-1;
        while(left<=right){
            if (p[left++] != p[right--]) return false;
        }
        return true;
    }
};