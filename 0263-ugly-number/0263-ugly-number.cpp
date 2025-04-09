class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (auto div : {2, 3, 5}) {
            helper(n, div);
        }
        return n == 1;
    }
private:
    void helper(int& n, int div) {
        while (n % div == 0) {
            n /= div; 
        }
    }
};