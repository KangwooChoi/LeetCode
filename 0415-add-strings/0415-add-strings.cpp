//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        string ans = "";
//        int carry = 0;
//        int sum = 0;
//        while (num1.length() != 0 && num2.length() != 0) {
//            int n1 = num1.back() - '0';
//            num1.pop_back();
//            int n2 = num2.back() - '0';
//            num2.pop_back();
//            sum = n1 + n2 + carry;
//            ans = to_string(sum%10) + ans; 
//            carry = sum / 10;
//        }
//        while (num1.length() != 0) {
//            int n1 = num1.back() - '0';
//            num1.pop_back();
//            sum = n1 + carry;
//            ans = to_string(sum%10) + ans;
//            carry = sum / 10;
//        }
//        while (num2.length() != 0) {
//            int n2 = num2.back() - '0';
//            num2.pop_back();
//            sum = n2 + carry;
//            ans = to_string(sum%10) + ans;
//            carry = sum / 10;
//        }
//        if (carry) ans = to_string(carry) + ans;
//        return ans;
//    }
//};
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