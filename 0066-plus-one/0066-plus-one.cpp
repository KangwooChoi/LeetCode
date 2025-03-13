class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            int digit = digits[i] + 1;
            if (digit == 10) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            } 
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        int n = digits.size();
//        for (int i = n-1; i >= 0; i--) {
//            int digit = digits[i];
//            if (digit == 9) {
//                digits[i] = 0;
//            } else {
//                digits[i]++;
//                return digits;
//            } 
//        }
//        digits.insert(digits.begin(), 1);
//        return digits; 
//    }
//};