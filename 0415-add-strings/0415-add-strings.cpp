class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        while(num1.length() != 0 || num2.length() != 0) {
            int digit1 = num1.empty() ? 0 : num1.back() - '0';
            int digit2 = num2.empty() ? 0 : num2.back() - '0';
            if (!num1.empty()) num1.pop_back();
            if (!num2.empty()) num2.pop_back();
            int temp = digit1 + digit2 + carry;
            ans = to_string(temp%10) + ans;
            carry = temp / 10;
        }
        if (carry) ans = to_string(carry) + ans;
        return ans;
    }
};