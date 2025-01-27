class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        vector<int> digit;
        while (x > 0) {
            int remain = x % 10;
            digit.push_back(remain);
            x /= 10;
        }
        int n = digit.size();
        int left = 0, right = n-1;
        while (left <= right) {
            if (digit[left++] != digit[right--]) return false;
        }
        return true; 
    }
};