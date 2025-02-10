class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0 || x == 1) return 1;
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }
        double ans = 1;
        while (n) {
            if (n % 2 == 1) {
                ans = ans * x;
                n--;
            }
            x = x * x;
            n = n / 2;
        }
        return ans;
    }

    double myPow(double x, int n) { return binaryExp(x, (long long)n); }
};
//class Solution {
//public:
//    double myPow(double x, int n) {
//        if (x == 1) return double(1);
//        if (n == 0) return double(1);
//        bool negative = n < 0 ? true : false;
//        if (negative) n = -n;
//        double ans = x;
//        while (--n > 0) {
//            ans *= x; 
//        }
//        return negative ? 1/ans : ans;
//    }
//};