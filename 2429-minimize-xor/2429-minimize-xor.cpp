class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            // Move to the next bit.
            currentBit++;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount) {
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            // Move to the next bit.
            currentBit++;
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};
//class Solution {
//public:
//    int minimizeXor(int num1, int num2) {
//        int ans = 0;
//        vector<int> n1_setbit = findSetBit(num1);
//        vector<int> n2_setbit = findSetBit(num2);
//        int n1_size = n1_setbit.size();
//        int n2_size = n2_setbit.size();
//        if (n1_size == n2_size) {
//            return num1;
//        } else if (n1_size > n2_size) {
//            int minus = 0;
//            int diff = n1_size - n2_size;
//            for (int i = 0; i < diff; i++) {
//                minus += 2^n1_setbit[i];
//            }
//            return num1 - minus;            
//        } else {
//
//        }
//
//
//        return ans;
//    }
//private:
//    vector<int> findSetBit(int num) {
//        int index = 0;
//        vector<int> ret;
//        while (num > 0) {
//            int remain = num % 2;
//            num /= 2;
//            if (remain == 1) ret.push_back(index);
//            index++;
//        }
//        return ret;
//    }
//};