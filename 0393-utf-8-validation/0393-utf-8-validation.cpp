class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numBytesToProcess = 0;
        int mask1 = 1 << 7;
        int mask2 = 1 << 6; 

        for (int i = 0; i < data.size(); i++) {
            if (numBytesToProcess == 0) {
                int mask = 1 << 7;
                while ((mask & data[i]) != 0) {
                    numBytesToProcess += 1;
                    mask = mask >> 1;
                }
                if (numBytesToProcess == 0) {
                    continue;
                }
                if (numBytesToProcess > 4 || numBytesToProcess == 1) {
                    return false;
                }
            } else {
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }
            numBytesToProcess -= 1;
        }
        return numBytesToProcess == 0;
    }
};