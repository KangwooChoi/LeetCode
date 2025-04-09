class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        } 
        return n == 1;
    }
private:
    int getNext(int x) {
        int res = 0;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            res += digit * digit;
        }
        return res;
    }
};