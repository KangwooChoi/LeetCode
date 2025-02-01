class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = num1;
        int targetSetBitsCount = __builtin_popcount(num2);
        int sourceSetBitsCount = __builtin_popcount(num1);

        int currBit = 0; 
        while (sourceSetBitsCount < targetSetBitsCount) {
            if (!isSet(ans, currBit)) {
                setBit(ans, currBit);
                sourceSetBitsCount++;
            }
            currBit++;
        }

        while (sourceSetBitsCount > targetSetBitsCount) {
            if (isSet(ans, currBit)) {
                unsetBit(ans, currBit);
                sourceSetBitsCount--;
            }
            currBit++;
        }

        return ans;
    }
private:
    bool isSet(int org, int bit) {
        return org & (1<<bit);
    }
    void setBit(int& org, int bit) {
        org |= (1<<bit);
    }
    void unsetBit(int& org, int bit) {
        org &= ~(1<<bit);
    }
};