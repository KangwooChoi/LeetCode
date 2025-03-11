class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0 ? true : false;
        long long nx = abs((long long)x);
        stack<long long> st;
        while (nx > 0) {
            st.push(nx%10);
            nx /= 10;
        } 
        long long ans = 0;
        long long mul = 1;
        while (!st.empty()) {
            ans += st.top() * mul; 
            st.pop();
            mul *= 10;
        }
        if (ans > INT_MAX) return 0;
        return isNegative ? (int)-ans : (int)ans;
    }
};