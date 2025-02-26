class Solution {
public:
    string addStrings(string num1, string num2) {
        //return to_string(stoi(num1) + stoi(num2));
        string ans = "";
        int p1 = num1.size() - 1, p2 = num2.size() - 1;
        int carry = 0;
        while (p1 >= 0 || p2 >= 0 || carry) {
            int digit1 = (p1 >= 0) ? num1[p1] - '0' : 0;
            int digit2 = (p2 >= 0) ? num2[p2] - '0' : 0;
            int total = digit1 + digit2 + carry;
            carry = total / 10;

            ans.push_back((total%10)+'0');
            p1--;
            p2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};