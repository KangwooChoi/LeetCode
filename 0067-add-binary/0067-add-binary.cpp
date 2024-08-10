class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m)
            return addBinary(b, a);
        
        string result;
        int carry = 0, j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;

            result.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry == 1) result.push_back('1');

        reverse(result.begin(), result.end());

        return result;

    }

};
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int numA = stoi(a, nullptr, 2);
//        int numB = stoi(b, nullptr, 2);
//        int sum = numA + numB;
//        if (sum == 0) return "0";
//        string binary = bitset<32>(sum).to_string();
//        cout << binary << endl;
//        return binary.substr(binary.find('1'));
//    }
//};