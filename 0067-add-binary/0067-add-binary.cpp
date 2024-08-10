class Bigint {
private:
    string binary;

    static void equalizeLength(string& a, string& b) {
        int lengthDiff = a.size() - b.size();
        if (lengthDiff > 0)
            b.insert(0, lengthDiff, '0');
        else
            a.insert(0, -lengthDiff, '0');
    }

    void removeLeadingZeros() {
        auto firstNonZero = binary.find_first_not_of('0');
        if (firstNonZero != string::npos) {
            binary.erase(0, firstNonZero);
        } else {
            binary = "0";
        }

    }

public:
    Bigint() : binary("0") {}

    Bigint (const string& bin) : binary(bin) { removeLeadingZeros(); }

    Bigint operator^(const Bigint& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char xorChar = (a[i] == b[i] ? '0' : '1');
            result.push_back(xorChar);
        }
        return Bigint(result);
    }

    Bigint operator&(const Bigint& other) const {
        string a = binary;
        string b = other.binary;
        equalizeLength(a, b);
        string result;
        for (size_t i = 0; i < a.size(); i++) {
            char andChar = (a[i] == '1' && b[i] == '1' ? '1' : '0');
            result.push_back(andChar);
        }
        return Bigint(result);
    }

    Bigint operator<<(int shift) const {
        string result = binary;
        result.append(shift, '0');
        return Bigint(result);
    }

    bool isZero() const {
        for (char c : binary)
            if (c != '0') return false;
        return true;
    }

    string getBinary() const { return binary; }

};

class Solution {
public:
    string addBinary(string a, string b) {
        Bigint x(a);
        Bigint y(b);
        Bigint carry, answer;

        while (!y.isZero()) {
            answer = x ^ y;
            carry = (x & y) << 1;
            x = answer;
            y = carry;
        }
        return x.getBinary();
    }
};
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int n = a.size(), m = b.size();
//        if (n < m)
//            return addBinary(b, a);
//        
//        string result;
//        int carry = 0, j = m - 1;
//        for (int i = n - 1; i >= 0; --i) {
//            if (a[i] == '1') ++carry;
//            if (j >= 0 && b[j--] == '1') ++carry;
//
//            result.push_back((carry % 2) ? '1' : '0');
//            carry /= 2;
//        }
//
//        if (carry == 1) result.push_back('1');
//
//        reverse(result.begin(), result.end());
//
//        return result;
//
//    }
//
//};
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