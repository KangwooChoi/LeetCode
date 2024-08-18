class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumSet;
        uglyNumSet.insert(1);

        long currUgly = 1;
        for (int i = 0; i < n; i++) {
            currUgly = *uglyNumSet.begin();
            uglyNumSet.erase(uglyNumSet.begin());

            uglyNumSet.insert(currUgly * 2);
            uglyNumSet.insert(currUgly * 3);
            uglyNumSet.insert(currUgly * 5);
        }

        return static_cast<int>(currUgly);
        
    }
};